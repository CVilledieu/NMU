#ifndef OBJECTS_H
#define OBJECTS_H

#include <glad/glad.h>
#include <stdlib.h>


typedef struct Object {
    float *colorValue;
    float *Position;
    float size;
    unsigned int *VAO;
}Object;

Object *CreatePlayer();

void SetCameraView(Object *obj);
void SetModel(Object *obj);

unsigned int *createArrayObject();
Object *CreateObject(float startingPos[3], float color[4]);

#endif