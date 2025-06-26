#include <objects.h>


Object *CreatePlayer(){
    float StartingPosition[3] = {0.0, 0.05, 0.0};
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->Position = StartingPosition;
    new->colorValue = AdjustedColorArray(0, 93, 34, 0.8);
    new->size = 20.0f;
    return new;
}