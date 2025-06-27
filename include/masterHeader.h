#ifndef MASTERHEADER_H
#define MASTERHEADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include <objects.h>
#include <shaders.h>
#include <util.h>
#include <state.h>
#include <draw.h>

//Global VAR
//Locations were initized:
//Main.c
extern unsigned int ShaderId;
extern GLFWwindow* wnd;

//State.c
extern enum GameState en_activeState;

//Util.c
extern int gi_Height;
extern int gi_Width;
extern float BackgroundColor[4];

#endif