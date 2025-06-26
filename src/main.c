#include <init.h>
#include <objects.h>

//Draw loop support functions
void StartLap();
void EndLap(GLFWwindow* wnd);

int main(void){
	App* app = Init();

	float obj1Color[4] = {0.0, 1.0, 0.0, 1.0};
	float obj2Color[4] = {0.0, 1.0, 1.0, 1.0};
	float loc[4] = {0.3, 0.0, 0.0, 0.5};
	float loc2[4] = {-0.8, -0.5, 0.0, 0.5};
	Object *newObject = CreateObject(loc,app->ShaderID, obj1Color);
	Object *secondObject = CreateObject(loc2, app->ShaderID, obj2Color);


	//Draw loop
	while(!glfwWindowShouldClose(app->wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(app->ShaderID);
		DrawObject(newObject);
		DrawObject(secondObject);

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