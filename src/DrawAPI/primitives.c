#include <glad/glad.h>
#include "DrawAPI.h"
#include <string.h>
#include <stdlib.h>
#include "shader.h"


void Cleanup_Model(Model *model) {
    glDeleteVertexArrays(1, &model->VAO);
    glDeleteBuffers(1, &model->VBO);
    glDeleteBuffers(1, &model->EBO);
}

//Initial function to easily create new meshs with different vertices
void SetNewMesh(vMesh *mesh){
    
    Vertex vertices[4] = {
        {-0.5, -0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.5, -0.5, 0.0, 1.0, 1.0, 0.0},
        {-0.5,  0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.5,  0.5, 0.0, 1.0, 1.0, 0.0}
    };
    mesh->VSize = 4;
    for(int i = 0; i < mesh->VSize; i++) {
        memcpy(mesh->vertex[i], vertices[i], sizeof(Vertex)); // Assuming vertex is an array, not pointer array
    }
    unsigned int indices[] = {0,1,2, 3,2,1};
    mesh->DSize = 6;
    
    mesh->drawOrder = malloc(mesh->DSize * sizeof(unsigned int));
    memcpy(mesh->drawOrder, indices, mesh->DSize * sizeof(unsigned int));
}

void SetModelVOs(Model *model){
    SetNewMesh(model->mesh);
    glGenVertexArrays(1, &model->VAO);
    glGenBuffers(1, &model->EBO);
    glGenBuffers(1, &model->VBO);

    glBindVertexArray(model->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, model->VBO);
    glBufferData(GL_ARRAY_BUFFER, 4*sizeof(Vertex), model->mesh->vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), model->mesh->drawOrder, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void DrawModel(Model *model){
    glUseProgram(Shader.ID);
    glBindVertexArray(model->VAO);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}



void SetModelMatrix(Model *model){
    float Matrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    memcpy(model->ModelMat4, Matrix, 16 * sizeof(float));

}



//Older method of drawing Vertexes
void SetMeshVertex(Mesh *mesh){
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, //Bottom Left
        0.5f, -0.5f, 0.0f, //Bottom Right 
        -0.5f, 0.5f, 0.0f, //Top Left
        0.5f, 0.5f, 0.0f // Top Right
    };

    unsigned int indices[] = {
        0,1,2, 3,2,1
    };
    mesh->VertexCount = sizeof(vertices);
    mesh->IndexCount = sizeof(indices);
    mesh->Vertices = malloc(mesh->VertexCount * sizeof(float));
    mesh->IndexList = malloc(mesh->IndexCount * sizeof(unsigned int));
    memcpy(mesh->Vertices, vertices, mesh->VertexCount * sizeof(float));
    memcpy(mesh->IndexList, indices, mesh->IndexCount * sizeof(unsigned int));   
}


void SetMeshVOs(Mesh *mesh){
    SetMeshVertex(mesh);
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &mesh->EBO);
    glGenBuffers(1, &mesh->VBO);

    glBindVertexArray(mesh->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->VertexCount, mesh->Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->IndexCount, mesh->IndexList, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

/*
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


}*/