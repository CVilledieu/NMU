#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <wndCalls.h>
#include <shaders.h>

#define STARTING_WIDTH 800
#define STARTING_HEIGHT 600
#define WND_TITLE "Needs More Upgrades"


unsigned int GetCompiledVertexShaderObj(void);
unsigned int GetCompiledFragShaderObj(void);
void setShaderProgram(void);


int main(void){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* wnd = glfwCreateWindow(STARTING_WIDTH,STARTING_HEIGHT,WND_TITLE, NULL, NULL);
	if (wnd == NULL){
		printf("%s\n", "Failed to create window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(wnd);
	

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("%s\n", "Failed to load Glad Proc Address");
		return -1;
	}
	//Range for init x and y: -1 to 1
	glViewport(0,0,STARTING_WIDTH,STARTING_HEIGHT);
	
	//Callbacks found in wndCallbacks.c
	glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
	glfwSetKeyCallback(wnd, keyPressCallback);
	
	//Rendering info
	float vertices[] ={
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};


	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	setShaderProgram();

	while(!glfwWindowShouldClose(wnd)){
		
		
		
		glClearColor(.2f,.3f,.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(wnd);
		glfwPollEvents();
	}
	


	glfwTerminate();
	return 0;
}

unsigned int GetCompiledVertexShaderObj(void){
	unsigned int vso;
	vso = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vso, 1,&vertexShaderSource, NULL);
	glCompileShader(vso);
	int ok =0;
	glGetShaderiv(vso, GL_COMPILE_STATUS, &ok);
	if(!ok){
		printf("%s\n", "Vertex Shader failed to compile!");
		return 0;
	}
	return vso;
}



unsigned int GetCompiledFragShaderObj(void){
	unsigned int fso;
	fso = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fso, 1, &fragShaderSource, NULL);
	glCompileShader(fso);

	int ok = 0;
	glGetShaderiv(fso, GL_COMPILE_STATUS, &ok);
	if(!ok){
		printf("%s\n","Fragment Shader failed to compile");
		return 0;
	}

	return fso;
}


void setShaderProgram(){
	unsigned int vertexShader;
	vertexShader = GetCompiledVertexShaderObj();
	if (vertexShader == 0){
		return 0;
	}

	unsigned int fragmentShader;
	fragmentShader = GetCompiledFragShaderObj();
	if (!fragmentShader){
		return 0;
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return;
}