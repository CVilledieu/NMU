#ifndef SHADERS_H
#define SHADERS_H


const char* Get_vertexShaderSource(void);
const char* Get_fragShaderSource(void);
unsigned int ShaderProgram(void);
void UpdateShaderUniform(unsigned int ShaderID, char* uniformId, float* newValues);

#endif