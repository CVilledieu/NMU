#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#define STARTING_WIDTH 800
#define STARTING_HEIGHT 600
#define WND_TITLE "Needs More Upgrades"

// Callbacks
void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);
void keyPressCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods);


//The initial steps needed to draw a window
//Sets Callbacks for frame size changing and for when key is pressed
GLFWwindow* SetUpMainWindow(void){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* wnd = glfwCreateWindow(STARTING_WIDTH,STARTING_HEIGHT,WND_TITLE, NULL, NULL);
	if (wnd == NULL){
		printf("%s\n", "Failed to create window");
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(wnd);
	

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("%s\n", "Failed to load Glad Proc Address");
		return NULL;
	}
	//Range for init x and y: -1 to 1
	glViewport(0,0,STARTING_WIDTH,STARTING_HEIGHT);
	
	//Callbacks found in wndCallbacks.c
	glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
	glfwSetKeyCallback(wnd, keyPressCallback);
    return wnd;
}

void keyPressCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods){
	if (action != GLFW_PRESS){
		return;
	}
	switch (key){
		case GLFW_KEY_ESCAPE: 
			glfwSetWindowShouldClose(wnd,1);
			break;
		default:
			break;
	}
	return;
}


void framebuffer_size_callback(GLFWwindow* wnd, int width, int height){
	glViewport(0,0,width, height);
}