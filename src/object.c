#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stdlib.h>
#include <objects.h>

typedef struct Object {
    unsigned int shaderId;
    float *colorValue;
    float *Position;
    float deltaY;
    float deltaX;
    unsigned int *VAO;
}Object;

Object *CreateObject(float pos[4], unsigned int ShaderID, float color[4]){
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->shaderId = ShaderID;
    new->Position = pos;
    new->colorValue = color;
    new->deltaY = 0;
    new->deltaX = 0;
    return new;
}

void viewMatrix(Object* obj, float scale[3], float rotate[3]){
    float Matrix[16] = {
        scale[0],   0,          0,          rotate[0],
        0,          scale[1],   0,          rotate[1],
        0,          0,          scale[2],   rotate[2],
        0,          0,          0,          1
    };
    int uniformLocation = glGetUniformLocation(obj->shaderId, "view");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}

void SetCameraView(Object *obj){
    //Global scaling values
    float sX = 0.1f;
    float sY = 0.1f;
    float sZ = 1.0f;
    //Translation to get Object into Position
    //Initial Value/Starting Position is set during object creation
    float tX = obj->Position[0];
    float tY = obj->Position[1];
    float tZ = 0.0f;

    //Column A = x || Column B = y || Column C = z
    float Matrix[16] = {
        sX,  0.0, 0.0, 0.0,
        0.0, sY,  0.0, 0.0,
        0.0, 0.0, sZ,  0.0,
        tX,  tY,  tZ,  1.0, //translation Row
    };

    int uniformLocation = glGetUniformLocation(obj->shaderId, "view");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}



void DrawObject(Object *obj){
    int ColorLoction = glGetUniformLocation(obj->shaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->colorValue);

    //Orientate Object based on world constants for size and angle
    SetCameraView(obj);
    obj->Position[0] += obj->deltaX;
        
    glBindVertexArray(*(obj->VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void moveObject(Object *obj, float dX, float dY){
    obj->deltaX = dX;
    obj->deltaY = dY;
}

unsigned int *createArrayObject(){
    unsigned int *VAO = malloc(sizeof(*VAO));
    glGenVertexArrays(1, VAO);
    glBindVertexArray(*VAO);
    float object[12] = {
        -0.5f, -0.5f, 0.0f, //Bottom Left
        0.5f, -0.5f, 0.0f, //Bottom Right 
        -0.5f, 0.5f, 0.0f, //Top Left
        0.5f, 0.5f, 0.0f // Top Right
    };

    unsigned int drawIndices[] = {
        0,1,2, 3,2,1
    };

    unsigned int VBO, EBO;
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(object), object, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(drawIndices), drawIndices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);//Unbind vertex Array
    glDeleteBuffers(1,&VBO);
    return VAO;
}