#include <glad/glad.h>
#include "DrawAPI.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




//Initial function to easily create new meshs with different vertices
void SetMesh(vMesh *mesh){
    
    Vertex vertices[] = {
        {-5.0, -5.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0, -5.0, 0.0, 1.0, 1.0, 0.0},
        {-5.0,  0.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.0, 0.0, 1.0, 1.0, 0.0},

        { 5.0,  5.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  5.0, 0.0, 1.0, 1.0, 0.0},
        { 5.0,  0.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.0, 0.0, 1.0, 1.0, 0.0},

    };
    mesh->VSize = 8;
    for(int i = 0; i < mesh->VSize; i++) {
        memcpy(&mesh->vertex[i], &vertices[i], sizeof(Vertex)); // Assuming vertex is an array, not pointer array
    }
    unsigned int indices[] = {0,1,2, 3,2,1,  4,5,6, 5,6,7};
    mesh->DSize = 12;
    
    mesh->drawOrder = malloc(mesh->DSize * sizeof(unsigned int));
    memcpy(mesh->drawOrder, indices, mesh->DSize * sizeof(unsigned int));
}

void SetModelVOs(Model *model){
    //SetMesh(model->mesh);
    glGenVertexArrays(1, &model->VAO);
    glGenBuffers(1, &model->EBO);
    glGenBuffers(1, &model->VBO);

    glBindVertexArray(model->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, model->VBO);
    glBufferData(GL_ARRAY_BUFFER, model->mesh->VeSize*sizeof(Vertex), model->mesh->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model->mesh->InSize * sizeof(unsigned int), model->mesh->DrawOrder, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}


void SetModelMatrix(Model *model){
    float Matrix[16] = {
        0.25f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    memcpy(model->ModelMat4, Matrix, 16 * sizeof(float));
}

void SetModelData(int ModelID){
    
    if(currentSc.ModCount >= MAX_MODELS) {
        printf("Error: Maximum models exceeded\n");
        
    }
    
    Model *newModel = malloc(sizeof(Model));
    if(!newModel) {
        printf("Error: Failed to allocate model\n");
        
    }
    
    vMesh *newMesh = malloc(sizeof(vMesh) + 8 * sizeof(Vertex));
    if(!newMesh) {
        printf("Error: Failed to allocate mesh\n");
        free(newModel);
        
    }
    
    SetMesh(newMesh);
    //newModel->mesh = newMesh;
    SetModelVOs(newModel);
    SetModelMatrix(newModel); 
    newModel->ID = ModelID;
    
    
    currentSc.ListOfModels[currentSc.ModCount] = newModel;
    currentSc.ModCount++;
    
}


Model *CreateModel(int ModelID){
    if(currentSc.ModCount >= MAX_MODELS){
        printf("Error: Max models already exist");
        return NULL;
    }

    Model *new = malloc(sizeof(Model));
    if(!new) {
        printf("Error: Failed to allocate model\n");
        return NULL;
    }
    

}


void DrawModel(Model *model){
    glBindVertexArray(model->VAO);

    int modelUniLoc = glGetUniformLocation(currentSc.ShaderID, "model");
    glUniformMatrix4fv(modelUniLoc, 1, GL_FALSE, model->ModelMat4); 

    glDrawElements(GL_TRIANGLES, model->mesh->InSize, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}


void Cleanup_Model(Model *model) {
    glDeleteVertexArrays(1, &model->VAO);
    glDeleteBuffers(1, &model->VBO);
    glDeleteBuffers(1, &model->EBO);
}