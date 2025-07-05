#include <glad/glad.h>
#include "DrawAPI.h"
#include <string.h>
#include <stdlib.h>

void SetMeshVertex(Mesh *mesh);

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

void Cleanup_Mesh(Mesh *mesh) {
    glDeleteVertexArrays(1, &mesh->VAO);
    glDeleteBuffers(1, &mesh->VBO);
    glDeleteBuffers(1, &mesh->EBO);
}

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


void DrawMesh(Mesh *mesh){
    SetProjectionUniform();

    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}