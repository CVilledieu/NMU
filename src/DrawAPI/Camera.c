#include "drawapi.h"



static float ProjectionMatrix[16] = {
    0.1f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float ViewMatrix[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.01f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


void UniformSet_View(){
    int UniformMtx = glGetUniformLocation(currentSc.ShaderID, "view");
    glUniformMatrix4fv(UniformMtx, 1, GL_FALSE, ViewMatrix);
}

void UniformSet_Projection(){
    int UniformLoc = glGetUniformLocation(currentSc.ShaderID, "projection");
    glUniformMatrix4fv(UniformLoc, 1, GL_FALSE, ProjectionMatrix); 
}