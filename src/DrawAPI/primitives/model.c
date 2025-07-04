#include <glad/glad.h>
#include "Shader.h"
#include "DrawAPI/Primitives.h"


void SetModel(Model *model){
    SetMeshVOs(model->Mesh);
    SetColorVec(model->ColorVec);
    GetModelMatrix(model->xformMatrix);
}


void GetModelMatrix(float *ModelMatrix){

    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
	float sY = 1.0f;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };
    ModelMatrix = Matrix;
}

void UpdateXformMatrix(float *xMatrix){
    float sX = 1.0f;
	float sY = 1.0f;
    float sZ = 1.0f;

    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };
    xMatrix = Matrix;
}


// Target: Object/Model itself. 
// Describes the object's size, orientation, and position
// Achieved by: Transforms from object's local coordinate space (model space) to world space
void SetModelMatrix(float *ModelMatrix){
	glUseProgram(Shader.Id);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
	float sY = 1.0f;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(Shader.Id, "world");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}




void BindObject(Object *obj){
    int ColorLoction = glGetUniformLocation(Shader.Id, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->Color_Vec4);
    
    int ModelLocation = glGetUniformLocation(Shader.Id, "model");
    glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, obj->Model_mat4);
    
    glBindVertexArray(*(obj->VertexObj_VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void DrawModel(Object *Obj){
    glUniform4fv(Shader.Color_uniformLoc, 1, Obj->Color_Vec4);
    glUniformMatrix4fv(Shader.Model_uniformLocation,1, GL_FALSE, Obj->ModelMatrix);

    glBindVertexArray(Obj->Model->VAO);


}