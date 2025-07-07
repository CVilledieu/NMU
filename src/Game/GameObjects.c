#include "DrawAPI.h"
//Initial function to easily create new meshs with different vertices
void SetMesh(vMesh *mesh){
    
    Vertex vertices[] = {
        {-0.5, -0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.0, -0.5, 0.0, 1.0, 1.0, 0.0},
        {-0.5,  0.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.0, 0.0, 1.0, 1.0, 0.0},

        { 0.5,  0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.5,  0.0, 0.0, 1.0, 1.0, 0.0},
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