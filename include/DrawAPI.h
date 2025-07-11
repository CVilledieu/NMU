#ifndef DRAWAPI_H
#define DRAWAPI_H

#define MAX_MODELS 32

#include <glad/glad.h>
//Vertex[0-2] = Position
//Vertex[3-5] = Color
//Future feature: Vertex[7-8] = Texcoord 
typedef float Vertex[6];
typedef float Matrix[16];

typedef struct {
    int VeSize;
    int InSize;
    unsigned int *DrawOrder;
    Vertex *vertices;
} Mesh;


typedef struct {
    int VSize;
    int DSize;
    unsigned int *drawOrder;
    Vertex vertex[];    
} vMesh;

typedef struct {
    unsigned int ID;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO;
    Matrix ModelMat4;
    Mesh *mesh;
} Model;


typedef struct {
    unsigned int ShaderID;
    int ModCount;
    Model *ListOfModels[MAX_MODELS];

} Scene;

//Global vars
extern Scene currentSc;

//Camera
void UniformSet_View();
void UniformSet_Projection();

//Scene Functions
void DrawScene();

void CleanUpScene();

//Shader Functions
void InitShaderProgram(char *FragfName, char *VertfName);

//model functions
void SetModelVOs(Model *model);
void SetModelMatrix(Model *model);
void SetModelData(int ModelID);
void Cleanup_Model(Model *model);
void DrawModel(Model *model);


//Mesh functions
void SetMesh(vMesh *m);

#endif