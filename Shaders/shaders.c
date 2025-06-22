#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <shaders.h>

typedef struct vertexObject{
    unsigned int* ID;
    float Color[4];
    char* uniformName;
}vertexObject;


const char* Get_vertexShaderSource(void){
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main(){\n"
        "gl_Position = vec4(aPos, 1.0);\n"
    "}\n\0";
    return vertexShaderSource;
}

const char* Get_fragShaderSource(void){
const char* fragShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec4 uniformColor;\n"
    "void main(){\n"
        "FragColor = uniformColor;\n"
    "}\n\0";
    return fragShaderSource;
}

// Shader functions
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


