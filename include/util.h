#ifndef UTIL_H
#define UTIL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include <objects.h>
#include <shaders.h>





//Draw loop functions

void DrawObjects(unsigned int ShadeId, Object **objs, int size);

//Main set up functions
void SetUpMainWindow(void);
void CreateShaderProgram(void);


void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);

#endif