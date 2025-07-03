#include "Shader.h"

ShaderPro Shader;

void SetUniformLoc(void);
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
	SetUniformLoc();
	return;
}

void SetUniformLoc(){
	Shader.Color_uniformLoc = glGetUniformLocation(Shader.ID, "color");
	Shader.Model_uniformLoc = glGetUniformLocation(Shader.ID, "model");
	Shader.View_uniformLoc = glGetUniformLocation(Shader.ID, "view");
	Shader.Proj_uniformLoc = glGetUniformLocation(Shader.ID, "projection");
}