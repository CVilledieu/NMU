#include <masterheader.h>

//Initialized Global variables
int gi_Height = 600;
int gi_Width = 800;
float BackgroundColor[4] = {0.0,0.0,0.0,1.0};

void framebuffer_size_callback(GLFWwindow* wnd, int width, int height){
	gi_Height = height;
	gi_Width = width;
	glViewport(0,0,width, height);
}

