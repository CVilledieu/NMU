#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stdio.h>
#include "wnd.h"
#include "DrawAPI.h"
#include "GameObjects.h"

Scene currentSc;

void clearBuffer(void);

int main(void){
	SetUpMainWindow();
	InitShaderProgram("Shaders/main.frag.glsl", "Shaders/main.vert.glsl");

	currentSc.ModCount = 0;
	SetPlayerData();
	//SetModelData(currentSc.ModCount); 


	while(!glfwWindowShouldClose(wnd)){
		clearBuffer();

		DrawScene();
		currentSc.ListOfModels[0]->ModelMat4[12] += (float).0005;

		glfwSwapBuffers(wnd);
    	glfwPollEvents();
	}
	
	CleanUpScene();
    glDeleteProgram(currentSc.ShaderID);
	glfwTerminate();
	return 0;
}

void clearBuffer(){
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

