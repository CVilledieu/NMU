#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <glfw/glfw3.h>


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




#endif