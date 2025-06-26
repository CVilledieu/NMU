#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stdlib.h>
#include <objects.h>

typedef struct Object {
    unsigned int shaderId;
    float *colorValue;
    float *startingPos;
    unsigned int *VAO;
}Object;

Object *CreateObject(float pos[4], unsigned int ShaderID, float color[4]){
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject();
    new->shaderId = ShaderID;
    new->startingPos = pos;
    new->colorValue = color;
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
    float Matrix[16] = {
        1.0,   0,   0,   0,
          0, 1.0,   0, 0.5,
          0,   0, 1.0,   0,
          0,   0,   0,   1,
    };
    int uniformLocation = glGetUniformLocation(obj->shaderId, "view");
    glUniformMatrix4fv(uniformLocation,1,GL_FALSE, Matrix);
}



void DrawObject(Object *obj){
    int ColorLoction = glGetUniformLocation(obj->shaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->colorValue);
    
    //Orientate Object based on world constants for size and angle
    SetCameraView(obj);
    
    //Put Object into position
    float newLoc[3] = {-0.5, 0.0, 0.0 }; 
    int uniformLocation = glGetUniformLocation(obj->shaderId, "move");
    glUniform3fv(uniformLocation,1, obj->startingPos);

    
    //
    glBindVertexArray(*(obj->VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
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