#ifndef UTIL_H
#define UTIL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>



//Main set up functions
void SetUpMainWindow(void);
void CreateShaderProgram(void);


void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);

#endif