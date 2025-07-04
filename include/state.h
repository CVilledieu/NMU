#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <glfw/glfw3.h>
#include <draw.h>

extern enum GameState en_activeState;
extern float BackgroundColor[4];

enum GameState {
    TITLE,
	MAIN_MENU,
	SETTINGS,
    GAME,
};

extern struct Object *current; 

void SetBackgroundColor(void);
void UpdateState(enum GameState newState);

void Title_Key_Callback(GLFWwindow* wnd, int key, int scancode, int action, int mods);
void Menu_Key_Callback(GLFWwindow* wnd, int key, int scancode, int action, int mods);
void Settings_Key_Callback(GLFWwindow* wnd, int key, int scancode, int action, int mods);
void Game_Key_Callback(GLFWwindow* wnd, int key, int scancode, int action, int mods);


void DrawTitle(void);


#endif