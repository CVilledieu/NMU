#ifndef SHADER_H
#define SHADER_H


extern ShaderPro Shader;

typedef struct ShaderPro{
	unsigned int ID;
	int Color_uniformLoc;
	int Model_uniformLoc;
	int View_uniformLoc;
	int Proj_uniformLoc;
}ShaderPro;



void CreateShaderProgram(void);
unsigned int FragmentShader_Obj(void);
unsigned int VertexShader(void);

#endif