#ifndef OBJECTS_H
#define OBJECTS_H


typedef struct Object {
    unsigned int shaderId;
    float *colorValue;
    float *Position;
    float deltaY;
    float deltaX;
    unsigned int *VAO;
}Object;

Object *CreatePlayer(unsigned int ShaderId);

void SetCameraView(Object *obj);
void moveObject(Object *obj, float dX, float dY);
void DrawObject(Object *obj);
unsigned int *createArrayObject();
Object *CreateObject(float startingPos[4], unsigned int ShaderID, float color[4]);

#endif