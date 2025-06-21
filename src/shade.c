#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <shaders.h>

typedef struct ShaderProgram{
    unsigned int ID;
    unsigned int *VAOs;
    int VAO_Size;
    unsigned int *VBOs;
    int VBO_Size;
}Shader;

typedef unsigned int ShaderID;

unsigned int VertexShader_Obj(void);
unsigned int FragmentShader_Obj(void);
void UpdateShaderUniform(unsigned int ShaderID, char* uniformId, float* newValues);

unsigned int ShaderProgram(){
	unsigned int vertexShader;
	vertexShader = VertexShader_Obj();
	if (vertexShader == 0){
		return 0;
	}

	unsigned int fragmentShader;
	fragmentShader = FragmentShader_Obj();
	if (!fragmentShader){
		return 0;
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

unsigned int VertexShader_Obj(void){
	unsigned int vso;
	vso = glCreateShader(GL_VERTEX_SHADER);
	const char* vsrc = Get_vertexShaderSource();
	glShaderSource(vso, 1, &vsrc, NULL);
	glCompileShader(vso);
	int ok =0;
	glGetShaderiv(vso, GL_COMPILE_STATUS, &ok);
	if(!ok){
		printf("%s\n", "Vertex Shader failed to compile!");
		return 0;
	}
	return vso;
}

unsigned int FragmentShader_Obj(void){
	unsigned int fso;
	fso = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fsrc = Get_fragShaderSource();
	glShaderSource(fso, 1, &fsrc, NULL);
	glCompileShader(fso);

	int ok = 0;
	glGetShaderiv(fso, GL_COMPILE_STATUS, &ok);
	if(!ok){
		printf("%s\n","Fragment Shader failed to compile");
		return 0;
	}

	return fso;
}


void UpdateShaderUniform(unsigned int ShaderID, char* uniformId, float* newValues){
    if (newValues[3] == '\0'){
        printf("%s\n", "Attempted to update Uniform Value with null pointer");
        return;
    }

    int uniformLocation = glGetUniformLocation(ShaderID, uniformId);
    glUniform4f(uniformLocation, (float)newValues[0], (float)newValues[1], (float)newValues[2], (float)newValues[3]);
}
