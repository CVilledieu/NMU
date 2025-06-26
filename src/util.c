#include <stdlib.h>

float* AdjustedColorArray(int R, int G, int B, int A){
    float* ColorArray = (float*)malloc(4 * sizeof(float));
    ColorArray[0] = R / 255.0f;
    ColorArray[1] = G / 255.0f;
    ColorArray[2] = B / 255.0f;
    ColorArray[3] = A / 1.0f;
    return ColorArray;
}