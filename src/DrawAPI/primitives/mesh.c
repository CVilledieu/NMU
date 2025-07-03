#include <glad/glad.h>
#include "Primitives/mesh.h"


void SetMeshVOs(Mesh *mesh){
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &mesh->EBO);
    glGenBuffers(1, &mesh->VBO);

    glBindVertexArray(mesh->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->VertexCount, mesh->Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->IndexCount, mesh->IndexList, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3*sizeof(float), (void*)0);
    glBindVertexArray(0);
}

void Cleanup_Mesh(Mesh *mesh) {
    glDeleteVertexArrays(1, &mesh->VAO);
    glDeleteBuffers(1, &mesh->VBO);
    glDeleteBuffers(1, &mesh->EBO);
}