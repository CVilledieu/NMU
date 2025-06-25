#ifndef DRAW_H
#define DRAW_H

#include <GLFW/glfw3.h>

typedef struct Object {
    unsigned int VAO;
    unsigned int size;
}Object;


Object* createObject(void);
void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]);


void new_EBO(float x, float y, float z, float r);
void BindMultiplePixels(unsigned int* VAOs);

#endif