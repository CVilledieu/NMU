#ifndef OBJECTS_H
#define OBJECTS_H


typedef struct Object {
    unsigned int shaderId;
    float *colorValue;
    float *startingPos;
    unsigned int *VAO;
}Object;

void SetCameraView(Object *obj);

void DrawObject(Object *obj);
unsigned int *createArrayObject();
Object *CreateObject(float startingPos[4], unsigned int ShaderID, float color[4]);

#endif