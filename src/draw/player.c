#include <masterheader.h>


Object *CreatePlayer(){
    float StartingPosition[3] = {0.0, 0.05, 0.0};
    float Color[4] = {1.0, 0.0,0.0,1.0};
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->Position = StartingPosition;
    new->colorValue = Color;
    new->size = 20.0f;
    return new;
}

