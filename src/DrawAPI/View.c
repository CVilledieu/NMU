#include "drawapi.h"

static Matrix ViewMatrix[16] = {
    0.1f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.05f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


void GetViewMtx(){
    int UniformMtx = glGetUniformLocation(currentSc.ShaderID, "view");
}