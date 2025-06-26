#include <init.h>
#include <objects.h>
#include <util.h>

//Draw loop support functions
void StartLap();
void EndLap(GLFWwindow* wnd);

int main(void){
	App* app = Init();

	float obj1Color[4] = {0.0, 1.0, 0.0, 1.0};
	float loc[4] = {0.3, 0.0, 0.0, 0.5};
	Object *newObject = CreateObject(loc,app->ShaderID, obj1Color);
	Object *Player = CreatePlayer(app->ShaderID);
	//Draw loop
	while(!glfwWindowShouldClose(app->wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(app->ShaderID);
		DrawObject(newObject);
		DrawObject(Player);

		//Ending a loop iteration
		EndLap(app->wnd);
	}

    glDeleteProgram(app->ShaderID);
	glfwTerminate();
	return 0;
}

void StartLap(){
	float* backgroundColor = AdjustedColorArray(60,60,60, 1);
    glClearColor(backgroundColor[0],backgroundColor[1],backgroundColor[2],backgroundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return;
}

void EndLap(GLFWwindow* wnd){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}