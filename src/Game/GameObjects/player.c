#include "DrawAPI.h"
#include <stdio.h>
#include <stdlib.h>

static int Player_VSize = 4;
static Vertex Player_Vertices[] = {
    { 2.0,  2.0,  0.0,  1.0,  1.0,  0.0},
    { 0.0,  2.0,  0.0,  1.0,  1.0,  0.0},
    { 2.0,  0.0,  0.0,  1.0,  1.0,  0.0},
    { 0.0,  0.0,  0.0,  1.0,  1.0,  0.0},
};

static int Player_DSize = 6;
static int Player_DrawOrder[] = {0,1,2, 3,2,1};


void SetPlayerMesh(Mesh *mesh){

    mesh->VeSize = 4;
    mesh->vertices = &Player_Vertices;
    mesh->InSize = 6;
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

