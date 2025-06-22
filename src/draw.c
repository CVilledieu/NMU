#include <glad/glad.h>
#include <GLFW/glfw3.h>

float colorArray[4] = {0.2f, 0.3f, 0.3f, 1.0f};


void StartLap(){
    glClearColor(colorArray[0], colorArray[1], colorArray[2], colorArray[3]);
	glClear(GL_COLOR_BUFFER_BIT);
    
    return;
}

void EndLap(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}


void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]){
    int vertexColorLocation = glGetUniformLocation(ShaderProgID, uniformName);
    glUniform4fv(vertexColorLocation,1, newValues);
}

