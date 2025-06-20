#ifndef UTIL_H
#define UTIL_H

#include <GLFW/glfw3.h>


//Draw loop support functions
void SetColor(float colorArray[4]);
void DrawStepSupport(GLFWwindow* wnd);


// Callbacks
void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);
void keyPressCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods);


#endif