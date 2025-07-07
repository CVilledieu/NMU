#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "DrawAPI.h"
#include <string.h>


unsigned int ccShader(char *fName, GLenum type);



void InitShaderProgram(char *FragfName, char *VertfName){
	currentSc.ShaderID = 0;
	currentSc.ShaderID = glCreateProgram();
	unsigned int FragID = ccShader(FragfName, GL_FRAGMENT_SHADER);
	unsigned int VertID = ccShader(VertfName, GL_VERTEX_SHADER);

	glAttachShader(currentSc.ShaderID, FragID);
	glAttachShader(currentSc.ShaderID, VertID);
	glLinkProgram(currentSc.ShaderID);

	int ok = 0;
	glGetProgramiv(currentSc.ShaderID, GL_LINK_STATUS, &ok);
	if(!ok){
		printf("Shaader failed to link");
		glfwTerminate();
	}


	glDeleteShader(FragID);
	glDeleteShader(VertID);
}



//Create and Compile Shader
unsigned int ccShader(char *fName, GLenum type ){

	unsigned int shObj = glCreateShader(type);

	FILE *fp;
	fp = fopen(fName, "rb");
	if (fp == NULL){
			printf("%s\n", "failed to open shader file");
			glfwTerminate();
		}

	fseek(fp, 0, SEEK_END);
	long length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *Src = (char *)malloc(length + 1);
	fread(Src, 1, length, fp);
	Src[length] = '\0';
	fclose(fp);

	const char *shSrc = Src;

	glShaderSource(shObj, 1, &shSrc, (void*)0);
	glCompileShader(shObj);

	int ok = 0;
	glGetShaderiv(shObj, GL_COMPILE_STATUS, &ok);
	if(!ok){
		glDeleteShader(shObj);
		printf("%s\n", "Shader failed to compile");
		glfwTerminate();
	}
	free(Src);
	return shObj;
}
