#ifndef INIT_H
#define INIT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <shaders.h>
#include <stdlib.h>

typedef struct App {
	GLFWwindow* wnd;
	unsigned int ShaderID;
}App;

App* Init();
GLFWwindow* SetUpMainWindow(void);
unsigned int ShaderProgram(void);


#endif