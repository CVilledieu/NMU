#include <glad/glad.h>
#include <stdlib.h>
#include <stdio.h>
#include "wnd.h"
#include "Shader.h"
#include "DrawAPI.h"


void clearBuffer(void);
unsigned int ShaderID;

int main(void){
	SetUpMainWindow();
	InitShaderProgram("Shaders/main.frag.glsl", "Shaders/main.vert.glsl");
	Model model;
	SetModelVOs(&model);
	SetModelMatrix(&model);
	int uniLoc = glGetUniformLocation(Shader.ID, "model");
	glUseProgram(Shader.ID);
	glUniformMatrix4fv(uniLoc, 1, GL_FALSE, model.ModelMat4); 
	
	while(!glfwWindowShouldClose(wnd)){
		clearBuffer();
		DrawModel(&model);



		glfwSwapBuffers(wnd);
    	glfwPollEvents();
	}
	
    glDeleteProgram(Shader.ID);
	Cleanup_Model(&model);
	glfwTerminate();
	return 0;
}

void clearBuffer(){
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}