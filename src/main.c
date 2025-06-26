#include <util.h>

#define WND_TITLE "Needs More Upgrades"

unsigned int ShaderId = 0;
GLFWwindow* wnd = NULL;

int main(void){
	SetUpMainWindow();
	CreateShaderProgram();
	float obj1Color[4] = {0.0, 1.0, 0.0, 1.0};
	float loc[3] = {0.0, 0.0, 0.0};
	Object *newObject = CreateObject(loc, obj1Color);
	Object *Player = CreatePlayer();
	//Draw loop
	while(!glfwWindowShouldClose(wnd)){
		//Processes needed for every loop iteration 
		//But not involving Drawing objects.
		StartLap();

		glUseProgram(ShaderId);
		
		DrawObject(Player);
		DrawObject(newObject);
		//Ending a loop iteration
		EndLap();
	}

    glDeleteProgram(ShaderId);
	glfwTerminate();
	return 0;
}



//Build up and break down functions for main draw loop
void StartLap(){
	float* backgroundColor = AdjustedColorArray(60,60,60, 1);
    glClearColor(backgroundColor[0],backgroundColor[1],backgroundColor[2],backgroundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return;
}

void EndLap(){
    glfwSwapBuffers(wnd);
    glfwPollEvents();
}

//The initial steps needed to draw a window
//Sets Callbacks for frame size changing and for when key is pressed
void SetUpMainWindow(void){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wnd = glfwCreateWindow(gi_Width,gi_Height,WND_TITLE, NULL, NULL);
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
	glfwSetKeyCallback(wnd, keyPressCallback);
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
	
	SetWorldScale();
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return;
}



void SetWorldScale(){
	glUseProgram(ShaderId);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = .9f;
	float sY = 1.0;
    float sZ = 1.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
         sX,  0.0, 0.0, 0.0,
        0.0,   sY, 0.0, 0.0,
        0.0,  0.0,  sZ, 0.0,
        0.0,  0.0, 0.0, 1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(ShaderId, "world");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}