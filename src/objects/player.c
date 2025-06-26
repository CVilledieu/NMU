#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <objects.h>
#include <util.h>
#include <stdlib.h>


Object *CreatePlayer(unsigned int ShaderId){
    float StartingPosition[4] = {-0.2, 0.0, 0.0, 1.0};
    float *PlayerColor = AdjustedColorArray(0, 93, 34, 0.8);
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->shaderId = ShaderId;
    new->Position = StartingPosition;
    new->colorValue = PlayerColor;
    new->deltaY = 0.0;
    new->deltaX = 0.00;
    return new;
}