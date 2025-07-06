#ifndef DRAWAPI_H
#define DRAWAPI_H

#include <glad/glad.h>

typedef float Vertex[6];

typedef struct {
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO; 
    int IndexCount;
    int VertexCount;
    unsigned int *IndexList;
    float *Vertices;
} Mesh;

typedef struct {
    int VSize;
    int DSize;
    unsigned int *drawOrder;
    Vertex vertex[4];    
} vMesh;

typedef struct {
    unsigned int ID;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO;
    float ModelMat4[16];
    vMesh *mesh;
} Model;


//Mesh functions
void SetMeshVOs(Mesh *mesh);
void Cleanup_Model(Model *model);
void DrawModel(Model *model);
void SetModelVOs(Model *model);
void SetNewMesh(vMesh *m);
void SetModelMatrix(Model *model);

#endif