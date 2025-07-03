#ifndef MESH_H
#define MESH_H

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