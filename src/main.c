#include <masterheader.h>
#include <windows.h>


unsigned int ShaderId = 0;
GLFWwindow* wnd = NULL;
void init(void);

int main(void){
	init();
	
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

void init(void){
	SetUpMainWindow();
	CreateShaderProgram();

	en_activeState = TITLE;
	UpdateState(en_activeState);
	
}

//The initial steps needed to draw a window
//Sets Callbacks for frame size changing and for when key is pressed
void SetUpMainWindow(void){
	char *WndTitle = "Needs More Upgrades";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wnd = glfwCreateWindow(gi_Width, gi_Height, WndTitle, NULL, NULL);
	if (wnd == NULL){
		printf("%s\n", "Failed to create window");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(wnd);
	

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("%s\n", "Failed to load Glad Proc Address");
		return ;
	}
	//Range for init x and y: -1 to 1
	glViewport(0,0,gi_Width,gi_Height);
	
	//Callbacks found in wndCallbacks.c
	glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
	glEnable(GL_DEPTH_TEST);

    return;
}


// Shader functions
void CreateShaderProgram(){
	unsigned int vertexShader;
	vertexShader = VertexShader();
	if (vertexShader == 0){
		glfwTerminate();
		return;
	}

	unsigned int fragmentShader;
	fragmentShader = FragmentShader_Obj();
	if (!fragmentShader){
		glfwTerminate();
		return;
	}

	ShaderId = glCreateProgram();
	glAttachShader(ShaderId, vertexShader);
	glAttachShader(ShaderId, fragmentShader);
	glLinkProgram(ShaderId);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return;
}

