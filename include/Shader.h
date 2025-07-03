#ifndef SHADER_H
#define SHADER_H


extern unsigned int ShaderId;
extern ShaderPro Shader;

void CreateShaderProgram(void);
unsigned int FragmentShader_Obj(void);
unsigned int VertexShader(void);

#endif