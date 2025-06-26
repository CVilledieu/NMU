#include <util.h>

//Initialized Global variables
int gi_Height = 600;
int gi_Width = 800;
unsigned int ShaderProgram;


float* AdjustedColorArray(int R, int G, int B, int A){
    float* ColorArray = (float*)malloc(4 * sizeof(float));
    ColorArray[0] = R / 255.0f;
    ColorArray[1] = G / 255.0f;
    ColorArray[2] = B / 255.0f;
    ColorArray[3] = A / 1.0f;
    return ColorArray;
}


//Callback function
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
	gi_Height = height;
	gi_Width = width;
	glViewport(0,0,width, height);
}