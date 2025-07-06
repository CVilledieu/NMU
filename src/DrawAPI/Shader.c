#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Shader.h"
#include <string.h>

ShaderPro Shader;

unsigned int ccShader(char *fName, GLenum type);



void InitShaderProgram(char *FragfName, char *VertfName){
	Shader.ID = glCreateProgram();

	unsigned int FragID = ccShader(FragfName, GL_FRAGMENT_SHADER);
	unsigned int VertID = ccShader(VertfName, GL_VERTEX_SHADER);

	glAttachShader(Shader.ID, FragID);
	glAttachShader(Shader.ID, VertID);
	glLinkProgram(Shader.ID);
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
		printf("%s\n", "Shader failed to compile");
		glfwTerminate();
	}
	return shObj;
}

/*
Old shaders
const char* Get_fragShaderSource(void){
const char* fragShaderSource = 
	"#version 330 core\n"
    "out vec4 Fragment;\n"
    "uniform vec4 color;\n"
    "void main(){\n"
        "Fragment = color;\n"
    "}\n\0";
    return fragShaderSource;
}


const char* VertexShaderSource(void){
	const char* shader = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 projection;\n"
		"uniform mat4 model;\n"
		"void main(){\n"
			"gl_Position = projection * model * vec4(aPos, 1.0);\n"
		"}\n\0";
		return shader;
}*/