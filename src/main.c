#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <util.h>
#include <shaders.h>

#define STARTING_WIDTH 800
#define STARTING_HEIGHT 600
#define WND_TITLE "Needs More Upgrades"



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

	unsigned int shaderProgram;
	shaderProgram = ShaderProgram();

	float miniTriforce[] = {
		0.0f, 0.5f, 0.0f, 	0.25f, 0.25f, 0.0f,	 -0.25f, 0.25f, 0.0f,
		0.25f, 0.25f, 0.0f, 0.5f, 0.0f, 0.0f,	 0.0f, 0.0f, 0.0f,
		-0.25f, 0.25f, 0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	};
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(miniTriforce), miniTriforce, GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	//Draw loop
	while(!glfwWindowShouldClose(wnd)){
		float background[4] = {0.2f, 0.3f, 0.3f, 1.0f};
		SetColor(background);

		glUseProgram(shaderProgram);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 9);

		DrawStepSupport(wnd);
	}
	
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

	glfwTerminate();
	return 0;
}


