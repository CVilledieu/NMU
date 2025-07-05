#include <glad/glad.h>
#include <stdio.h>

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
}

unsigned int VertexShader(void){
	unsigned int vso;
	vso = glCreateShader(GL_VERTEX_SHADER);
	const char* vsrc = VertexShaderSource();
	glShaderSource(vso, 1, &vsrc, (void*)0);
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
	glShaderSource(fso, 1, &fsrc, (void*)0);
	glCompileShader(fso);

	int ok = 0;
	glGetShaderiv(fso, GL_COMPILE_STATUS, &ok);
	if(!ok){
		printf("%s\n","Fragment Shader failed to compile");
		return 0;
	}

	return fso;
}


