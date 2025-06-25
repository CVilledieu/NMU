#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <wnd_init.h>
#include <draw.h>
#include <shaders.h>


//Draw loop support functions
void StartLap();
void EndLap(GLFWwindow* wnd);

void BufferObject();
void DrawObjects(unsigned int* VAO, int size);
void BindMultiplePixels(unsigned int* VAOs);


int main(void){
	GLFWwindow* wnd = SetUpMainWindow();
	if (wnd == NULL){
		return -1;
	}

	unsigned int shaderProgram = ShaderProgram();

	//unsigned int VAOs[2];
	//VAOs[0] = 0;
	//VAOs[1] = 0;
	//glGenVertexArrays(2, VAOs);
	//BindMultiplePixels(VAOs);

	float uniValues[4] = {0.0, 1.0, 0.0, 1.0};
	Object* new = createObject();
	
	//Draw loop
	while(!glfwWindowShouldClose(wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(shaderProgram);
		
        updateUniformColor(shaderProgram, "uniformColor", uniValues);
		//DrawObjects(VAOs, 2);
		glBindVertexArray(new->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//Ending a loop iteration
		EndLap(wnd);
	}
	
	//glDeleteVertexArrays(2, VAOs);

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

void DrawObjects(unsigned int* VAOs, int size){
	for (int i = 0; i < size; i++){
		glBindVertexArray(VAOs[i]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	glBindVertexArray(0);
}

void StartLap(){
	float colorArray[4] = {0.2f, 0.3f, 0.3f, 1.0f};
    glClearColor(colorArray[0], colorArray[1], colorArray[2], colorArray[3]);
	glClear(GL_COLOR_BUFFER_BIT);
    
    return;
}

void EndLap(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}