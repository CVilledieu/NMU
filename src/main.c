#include <init.h>
#include <draw.h>


//Draw loop support functions
void StartLap();
void EndLap(GLFWwindow* wnd);

int main(void){
	App* app = Init();

	float uniValues[4] = {0.0, 1.0, 0.0, 1.0};
	float uniformValues[4] = {0.0, 1.0, 1.0, 1.0};
	float loc[4] = {0.0, 0.0, 0.0, 0.5};
	float loc2[4] = {0.1, -0.5, 0.0, 0.5};
	Object *newObject = CreateObject(loc,app->ShaderID);
	Object *secondObject = CreateObject(loc2, app->ShaderID);
	setObjectColor(newObject, uniValues);
	setObjectColor(secondObject, uniformValues);

	//Draw loop
	while(!glfwWindowShouldClose(app->wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(app->ShaderID);
		DrawObject(newObject);
		DrawObject(secondObject);
		float changingLocation[4] = {0, 0.002f, 0, 0};
		MoveObject(secondObject, changingLocation);
		//Ending a loop iteration
		EndLap(app->wnd);
	}

    glDeleteProgram(app->ShaderID);
	glfwTerminate();
	return 0;
}

void StartLap(){
	float colorArray[4] = {0.2f, 0.3f, 0.3f, 1.0f};
    glClearColor(colorArray[0], colorArray[1], colorArray[2], colorArray[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return;
}

void EndLap(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}