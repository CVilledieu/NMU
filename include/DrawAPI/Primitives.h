#ifndef PRIMITIVES_H
#define PRIMITIVES_H




typedef struct Model {
    unsigned int ID;
    Mesh *Mesh;
    float ColorVec[4];
    float xformMatrix[16];
} Model;



typedef struct Mesh{
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO; 
    int IndexCount;
    int VertexCount;
    unsigned int *IndexList; // CPU copy of index data
    float *Vertices;         // CPU copy of vertex data
} Mesh;

void SetMeshVOs(Mesh *mesh);


#endif