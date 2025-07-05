#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stdio.h>
#include "Shader.h"

ShaderPro Shader;


// Shader functions
void CreateShaderProgram(){
	unsigned int vertexShader;
	vertexShader = VertexShader();
	if (vertexShader == 0){
		glfwTerminate();
		return;
	}

	unsigned int fragmentShader;
	fragmentShader = FragmentShader_Obj();
	if (!fragmentShader){
		glfwTerminate();
		return;
	}

	Shader.ID = glCreateProgram();
	glAttachShader(Shader.ID, vertexShader);
	glAttachShader(Shader.ID, fragmentShader);
	glLinkProgram(Shader.ID);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return;
}


void loadShader(){

}