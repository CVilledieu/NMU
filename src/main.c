#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <wndCalls.h>

#define STARTING_WIDTH 800
#define STARTING_HEIGHT 600
#define WND_TITLE "Needs More Upgrades"


void handleUserInput(GLFWwindow* wnd);


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
	

	while(!glfwWindowShouldClose(wnd)){
		
		
		
		glClearColor(.2f,.3f,.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(wnd);
		glfwPollEvents();
	}
	


	glfwTerminate();
	return 0;
}

