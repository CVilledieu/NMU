#include <glad/glad.h>
#include "Shader.h"




void SetProjectionUniform(){
    float Matrix[16] = {
        1.0,  0.0,  0.0, 0.0,
        0.0,  1.0,  0.0, 0.0,
        0.0,  0.0,  1.0, 0.0,
        0.0,  0.0,  0.0, 0.0, //translation Row
    };
    unsigned int Projection = glGetUniformLocation(Shader.ID, "projection");
    glUniformMatrix4fv(Projection,1, GL_FALSE, Matrix);
}

/*
void ProjectionMatrix(){
    float Xa;   // (2n / (r-l))
    float Yb;   // (2n / (t-b))
    float Za, Zb,Zc; // ((r+l)/(r-l)), ((t+b)/(t-b)), (-(f+n) / (f-n))
    float Tc; // (2fn / (f-n))

    float Matrix[16] = {
         Xa, 0.0,   Za, 0.0,
        0.0,  Yb,   Zb, 0.0,
        0.0, 0.0,   Zc,  Tc,
        0.0, 0.0, -1.0, 0.0,
    };
}
*/
