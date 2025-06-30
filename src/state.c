#include <masterheader.h>


enum GameState {
    TITLE,
	MAIN_MENU,
	SETTINGS,
    GAME,
};

enum GameState en_activeState = TITLE;

void SetBackgroundColor(void){
	switch (en_activeState){
		case TITLE:
				BackgroundColor[0] = 0.0f;
				BackgroundColor[1] = 0.0f;
				BackgroundColor[2] = 0.0f;
				BackgroundColor[3] = 1.0f;
			break;
		case MAIN_MENU:
				BackgroundColor[0] = 0.23f;
				BackgroundColor[1] = 0.23f;
				BackgroundColor[2] = 0.2f;
				BackgroundColor[3] = 1.0f;
			break;
		case SETTINGS:
				BackgroundColor[0] = 0.9176f;
				BackgroundColor[1] = 0.7137f;
				BackgroundColor[2] = 0.4627f;
				BackgroundColor[3] = 1.0f;
			break;
		case GAME:
				BackgroundColor[0] = 0.9176f;
				BackgroundColor[1] = 0.7137f;
				BackgroundColor[2] = 0.4627f;
				BackgroundColor[3] = 1.0f;
			break;

	}
}

void UpdateState(enum GameState newState){
	en_activeState = newState;
	SetBackgroundColor();
	switch (en_activeState){
		case TITLE:
			glfwSetKeyCallback(wnd, Title_Key_Callback);
			float Position[3] = {0.0f, 0.0f, 0.0f};
			float Color[4] = {1.0f, 0.0f, 1.0f, 1.0f};
			SetProjectionMatrix();
    		SetViewMatrix();    
   			SetModelMatrix();

			break;
		case MAIN_MENU:
			glfwSetKeyCallback(wnd, Menu_Key_Callback);
			break;
		case SETTINGS:
			glfwSetKeyCallback(wnd, Settings_Key_Callback);
			break;
		case GAME:
			glfwSetKeyCallback(wnd, Game_Key_Callback);
			break;
	}


}
