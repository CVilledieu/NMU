#include <util.h>

void SetColor(float colorArray[4]){
    glClearColor(colorArray[0], colorArray[1], colorArray[2], colorArray[3]);
	glClear(GL_COLOR_BUFFER_BIT);
    
    return;
}

void DrawStepSupport(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}