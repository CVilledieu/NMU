#include <glad/glad.h>
#include <stdlib.h>
#include <stdio.h>
#include "wnd.h"
#include "Shader.h"
#include "DrawAPI.h"


void backdrop(){
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



int main(void){
	SetUpMainWindow();
	CreateShaderProgram();
	Mesh mesh;
	SetMeshVOs(&mesh);

	
	while(!glfwWindowShouldClose(wnd)){
		backdrop();
		DrawMesh(&mesh);



		glfwSwapBuffers(wnd);
    	glfwPollEvents();
	}
	
	DrawLoop();

    glDeleteProgram(Shader.ID);
	Cleanup_Mesh(&mesh);
	glfwTerminate();
	return 0;
}

