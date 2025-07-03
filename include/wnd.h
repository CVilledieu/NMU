#ifndef MAINWND_H
#define MAINWND_H

extern int gi_WndHeight;
extern int gi_WndWidth;

extern GLFWwindow* wnd;

void SetUpMainWindow(void);
void framebuffer_size_callback(GLFWwindow* wnd, int width, int height);

#endif