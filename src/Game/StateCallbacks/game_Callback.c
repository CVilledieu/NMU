#include "state.h"

//Callback function
void Game_Key_Callback(GLFWwindow* wnd, int key, int scancode, int action, int mods){
	if (action != GLFW_PRESS){
		return;
	}
	switch (key){
		case GLFW_KEY_ESCAPE: 
			glfwSetWindowShouldClose(wnd,1);
			break;
		case GLFW_KEY_SPACE:
			UpdateState(TITLE);
			break;
		default:
			break;
	}
	return;
}