#include "DrawAPI.h"

static Square_VSize = 8;
static Vertex Square_Vertices[] = {
        {-0.5,  0.5, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.5, 0.0, 1.0, 1.0, 0.0},
        {-0.5,  0.0, 0.0, 1.0, 1.0, 0.0},
        { 0.0,  0.0, 0.0, 1.0, 1.0, 0.0},

        { 0.5, -0.5, 0.0, 0.0, 0.8, 0.8},
        { 0.0, -0.5, 0.0, 1.0, 0.8, 0.8},
        { 0.5,  0.0, 0.0, 1.0, 0.8, 0.8},
        { 0.0,  0.0, 0.0, 1.0, 0.8, 0.8},

};

static Square_DSize = 12;
static int Square_DrawOrder[] = {0,1,2, 3,2,1,  4,5,6, 5,6,7};

static StdSqrDrawIndices[] = {0,1,2 ,1,2,3};

void SetSquareMesh(Mesh *mesh){

    mesh->VeSize = 8;
    mesh->vertices = &Square_Vertices;
    mesh->InSize = 12;
    mesh->DrawOrder = &Square_DrawOrder;
    
}

void SetSquareData(){
     if(currentSc.ModCount >= MAX_MODELS) {
        printf("Error: Maximum models exceeded\n");
        
    }
    
    Model *playerModel = malloc(sizeof(Model));
    if(!playerModel) {
        printf("Error: Failed to allocate model\n");
        
    }
    
    SetPlayerMesh(playerModel->mesh);
    SetModelVOs(playerModel);
    SetModelMatrix(playerModel); 
    playerModel->ID = currentSc.ModCount;
    
    
    currentSc.ListOfModels[currentSc.ModCount] = playerModel;
    currentSc.ModCount++;
}
