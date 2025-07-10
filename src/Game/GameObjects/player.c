#include "DrawAPI.h"
#include <stdio.h>
#include <stdlib.h>

static Player_VSize = 8;
static Vertex Player_Vertices[] = {
    {-0.5,  0.5, 0.0, 1.0, 1.0, 0.0},
    { 0.0,  0.5, 0.0, 1.0, 1.0, 0.0},
    {-0.5,  0.0, 0.0, 1.0, 1.0, 0.0},
    { 0.0,  0.0, 0.0, 1.0, 1.0, 0.0},

    { 0.5, -0.5, 0.0, 0.0, 0.8, 0.8},
    { 0.0, -0.5, 0.0, 1.0, 0.8, 0.8},
    { 0.5,  0.0, 0.0, 1.0, 0.8, 0.8},
    { 0.0,  0.0, 0.0, 1.0, 0.8, 0.8},

};

static Player_DSize = 12;
static Player_DrawOrder[] = {0,1,2, 3,2,1,  4,5,6, 5,6,7};


void SetPlayerMesh(Mesh *mesh){

    mesh->VeSize = 8;
    mesh->vertices = &Player_Vertices;
    mesh->InSize = 12;
    mesh->DrawOrder = &Player_DrawOrder;
    
}

void SetPlayerData(){
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

