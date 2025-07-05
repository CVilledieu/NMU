#ifndef SHADER_H
#define SHADER_H




typedef struct ShaderPro{
	unsigned int ID;
}ShaderPro;

extern ShaderPro Shader;

void CreateShaderProgram(void);
unsigned int FragmentShader_Obj(void);
unsigned int VertexShader(void);

#endif