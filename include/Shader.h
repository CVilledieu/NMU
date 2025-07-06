#ifndef SHADER_H
#define SHADER_H




typedef struct {
	unsigned int ID;

}ShaderPro;

extern ShaderPro Shader;
extern unsigned int ShaderID;

void InitShaderProgram(char *FragfName, char *VertfName);


#endif