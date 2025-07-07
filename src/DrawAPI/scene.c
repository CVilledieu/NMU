#include "DrawAPI.h"
#include <string.h>
#include <stdlib.h>


void InitViewMat(){
    
    Matrix mat = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    memcpy(currentSc.ViewMat4, mat, sizeof(Matrix));
}

void DrawScene(){
    glUseProgram(currentSc.ShaderID);
    int viewUniLoc = glGetUniformLocation(currentSc.ShaderID, "view");
    glUniformMatrix4fv(viewUniLoc, 1, GL_FALSE, currentSc.ViewMat4);
    for (int i =0; i < currentSc.ModCount; i++){
        DrawModel(currentSc.ListOfModels[i]);
    }
    
}


void CleanUpScene(){
    for (int i = 0; i < currentSc.ModCount; i++){
        Model *mod = currentSc.ListOfModels[i];
        free(mod->mesh->drawOrder);
        free(mod->mesh);
        free(mod);
    }
}


