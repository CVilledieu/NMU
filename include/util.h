#ifndef UTIL_H
#define UTIL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include <objects.h>
#include <shaders.h>

extern int gi_Height;
extern int gi_Width;
extern unsigned int ShaderId;
extern GLFWwindow* wnd;

float* AdjustedColorArray(int R, int G, int B, int A);


//Draw loop support functions
void StartLap(void);
void EndLap(void);

//Main set up functions
void SetUpMainWindow(void);
void CreateShaderProgram(void);
void SetWorldScale(void);
//Callbacks
void keyPressCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);


#endif