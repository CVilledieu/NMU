#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

GLFWwindow* wnd = NULL;
int gi_WndHeight = 600;
int gi_WndWidth = 800;


void framebuffer_size_callback(GLFWwindow* wnd, int width, int height){
	gi_WndHeight = height;
	gi_WndWidth = width;
	glViewport(0,0,width, height);
}

//Call back parameters:GLFWwindow* wnd, int key, int scancode, int action, int mods
void UserInput_Callback(GLFWwindow* wind, int key, int scancode, int action, int mods){
	//Currently unused Parameters, but required by Callback function
	(void)wind;
	(void)scancode;
	(void)mods;
	if (action != GLFW_PRESS){
		return;
	}
	switch(key){
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(wnd,1);
			break;
		case GLFW_KEY_W:
			break;
		default:

			break;
	}
	
}


//The initial steps needed to draw a window
//Sets Callbacks for frame size changing and for when key is pressed
void SetUpMainWindow(void){
	char *WndTitle = "Needs More Upgrades";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wnd = glfwCreateWindow(gi_WndWidth, gi_WndHeight, WndTitle, NULL, NULL);
	if (wnd == NULL){
		printf("%s\n", "Failed to create window");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(wnd);
	

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("%s\n", "Failed to load Glad Proc Address");
		return ;
	}
	//Range for init x and y: -1 to 1
	glViewport(0,0,gi_WndWidth,gi_WndHeight);
	
	//Callbacks found in wndCallbacks.c
	glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
	glfwSetKeyCallback(wnd, UserInput_Callback);
	glEnable(GL_DEPTH_TEST);
	
    return;
}

