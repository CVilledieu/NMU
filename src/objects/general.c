#include <util.h>


typedef struct Object {
    float *colorValue;
    float *Position;
    float size;
    unsigned int *VAO;
}Object;

Object *CreateObject(float pos[3], float color[4]){
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->Position = pos;
    new->colorValue = color;
    new->size = 60.0f;
    return new;
}

void SetCameraView(Object *obj){
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    float sX = 1.0f;
    float sY = 1.0f;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(ShaderId, "view");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}




void SetModel(Object *obj){
    float tX = obj->Position[0];
    float tY = obj->Position[1];
    float tZ = obj->Position[2];

    float Matrix[16] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
         tX,  tY,  tZ, 1.0,
    };
    int uniformLocation = glGetUniformLocation(ShaderId, "model");
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, Matrix);
}
