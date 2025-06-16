#include <wndCalls.h>

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