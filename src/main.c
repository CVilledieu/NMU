#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <wnd_init.h>
#include <draw.h>
#include <shaders.h>


void BufferObject();
void DrawObjects(unsigned int* VAO, int size);
const float BasicTriangle[9] = {
        -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
    };



int main(void){
	GLFWwindow* wnd = SetUpMainWindow();
	if (wnd == NULL){
		return -1;
	}

	unsigned int shaderProgram;
	shaderProgram = ShaderProgram();

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	BufferObject();
	

	float uniValues[4] = {0.0, 1.0, 0.0, 1.0};

   
	//Draw loop
	while(!glfwWindowShouldClose(wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(shaderProgram);
		
        updateUniformColor(shaderProgram, "uniformColor", uniValues);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0,3);

		//Ending a loop iteration
		EndLap(wnd);
	}
	
	glDeleteVertexArrays(1, &VAO);

    glDeleteProgram(shaderProgram);

	glfwTerminate();
	return 0;
}




void BufferObject(){
	float Triangle[9] = {
        -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
    };

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), Triangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void DrawObjects(unsigned int* VAO, int size){
	for (int i = 0; i < size; i++){
		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_TRIANGLES, 0,3);
	}
}