#include <glad/glad.h>
#include "Shader.h"
#include "DrawAPI/Primitives.h"

typedef struct FrameData{
    float **View_Matrix;
    float **Proj_Matrix;
    Object *Renderables;
}FrameData;

FrameData CurrentFD;

void SetFrameUniformsData(){
    glUniformMatrix4fv(Shader.View_uniformLoc, 1, GL_FALSE, CurrentFD.View_Matrix);
    glUniformMatrix4fv(Shader.Proj_uniformLoc, 1, GL_FALSE, CurrentFD.Proj_Matrix);
}


// Target: The "world itself"
// Describes: Scales ojects based on depth
void SetProjectionMatrix(){
	glUseProgram(Shader.ID);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
	float sY = 1.0;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    CurrentFD.Proj_Matrix = &Matrix;
}

// Target: The view from the viewport / the "Camera"
// Describes: Camera Position, Orientation, and direction it is facing
// Achieved by: Transforms from world space to camera space (also known as eye space)
void SetViewMatrix(){
	glUseProgram(Shader.Id);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
	float sY = 1.0;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(ShaderId, "world");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}