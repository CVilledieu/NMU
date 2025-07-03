#include <glad/glad.h>
#include "state.h"
#include "wnd.h"
#include "Shader.h"


int main(void){
	SetUpMainWindow();
	CreateShaderProgram();

	en_activeState = TITLE;
	UpdateState(en_activeState);
	
	while(!glfwWindowShouldClose(wnd)){
		glClearColor(BackgroundColor[0],BackgroundColor[1],BackgroundColor[2],BackgroundColor[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		switch (en_activeState){
			case TITLE:
				DrawTitle();
				break;
			case MAIN_MENU:
				break;	
			case SETTINGS:
				break;
			case GAME:
				break;
		}

		//Ending a loop iteration
		glfwSwapBuffers(wnd);
    	glfwPollEvents();
	}

    glDeleteProgram(ShaderId);
	glfwTerminate();
	return 0;
}


