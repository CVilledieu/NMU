#include "DrawAPI.h"
#include <string.h>
#include <stdlib.h>


void DrawScene(){
    glUseProgram(currentSc.ShaderID);
    
    UniformSet_View();
    UniformSet_Projection();

    for (int i =0; i < currentSc.ModCount; i++){
        Model *model = currentSc.ListOfModels[i];
        int modelUniLoc = glGetUniformLocation(currentSc.ShaderID, "model");
        DrawModel(model);
    }
    
}


void CleanUpScene(){
    for (int i = 0; i < currentSc.ModCount; i++){
        Model *mod = currentSc.ListOfModels[i];
        free(mod->mesh->DrawOrder);
        free(mod->mesh);
        free(mod);
    }
}


