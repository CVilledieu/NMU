#ifndef DRAW_H
#define DRAW_H

#include <GLFW/glfw3.h>

typedef struct Object {
    unsigned int shaderId;
    float *colorValue;
    float *location;
    unsigned int *VAO;
}Object;

Object *CreateObject(float location[4], unsigned int ShaderID);
unsigned int *createArrayObject(float location[4]);
void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]);
void setObjectColor(Object *obj, float color[4]);
void DrawObject(Object *obj);
void MoveObject(Object *obj, float *delta);


#endif