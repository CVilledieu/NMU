#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

const char* Get_fragShaderSource(void){
const char* fragShaderSource = 
	"#version 330 core\n"
    "out vec4 Fragment;\n"
    "uniform vec4 uniformColor;\n"
    "void main(){\n"
        "Fragment = uniformColor;\n"
    "}\n\0";
    return fragShaderSource;
}

const char* VertexShaderSource(void){
	const char* shader = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 view;\n"
		"uniform vec3 move;\n"
		"void main(){\n"
			"gl_Position = view * vec4((aPos + move), 1.0);\n"
		"}\n\0";
		return shader;
}

unsigned int VertexShader(void){
	unsigned int vso;
	vso = glCreateShader(GL_VERTEX_SHADER);
	const char* vsrc = VertexShaderSource();
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


