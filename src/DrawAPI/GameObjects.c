#include <glad/glad.h>
#include "Shader.h"
#include "state.h"

typedef struct FrameData{
    float **View_Matrix;
    float **Proj_Matrix;
    Object *Renderables;
}FrameData;

FrameData CurrentFD;

typedef struct Object{
    unsigned int ID;
    struct Mesh *Mesh;
    Uniforms_Model *uniforms;
}Object;

typedef struct Uniforms_Model{
    float **Color_Vec4;
    float **Model_Mat4fv;
} Uniforms_Model;

typedef struct Mesh{
    unsigned int VAO;
    unsigned int VBO;        // Track for cleanup & updates
    unsigned int EBO;        // Track for cleanup
    int vertexCount;
    int indexCount;
    unsigned int *IndexList; // CPU copy of index data
    float *Vertices;         // CPU copy of vertex data
} Mesh;

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



void SetFrameUniformsData(){
    glUniformMatrix4fv(Shader.View_uniformLoc, 1, GL_FALSE, CurrentFD.View_Matrix);
    glUniformMatrix4fv(Shader.Proj_uniformLoc, 1, GL_FALSE, CurrentFD.Proj_Matrix);
}

void DrawObject(Object *Obj){
    glUniform4fv(Shader.Color_uniformLoc, 1, Obj->Color_Vec4);
    glUniformMatrix4fv(Shader.Model_uniformLocation,1, GL_FALSE, Obj->ModelMatrix);

    glBindVertexArray(Obj->Model->VAO);


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

