#include <glad/glad.h>
#include "Shader.h"
#include "Primitives/model.h"
#include "Primitives/mesh.h"

// Target: Object/Model itself. 
// Describes the object's size, orientation, and position
// Achieved by: Transforms from object's local coordinate space (model space) to world space
void SetModelMatrix(){
	glUseProgram(ShaderId);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
	float sY = 1.0;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(ShaderId, "world");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}




void BindObject(Object *obj){
    int ColorLoction = glGetUniformLocation(ShaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->Color_Vec4);
    
    int ModelLocation = glGetUniformLocation(ShaderId, "model");
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