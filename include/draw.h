#ifndef DRAW_H
#define DRAW_H

#include <GLFW/glfw3.h>

//Draw loop support functions
void StartLap();
void EndLap(GLFWwindow* wnd);

void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]);
float* GetVertexArray(void);

#endif