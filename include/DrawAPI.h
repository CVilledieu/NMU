#ifndef DRAWAPI_H
#define DRAWAPI_H


//Primative types

typedef struct Mesh{
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO; 
    int IndexCount;
    int VertexCount;
    unsigned int *IndexList;
    float *Vertices;
} Mesh;


//Frame functions
void SetProjectionUniform();

//Mesh functions
void SetMeshVOs(Mesh *mesh);
void Cleanup_Mesh(Mesh *mesh);
void DrawMesh(Mesh *mesh);


#endif