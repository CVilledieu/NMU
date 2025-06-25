#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>


typedef struct Object {
    unsigned int VAO;
    unsigned int size;
}Object;



void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]){
    int vertexColorLocation = glGetUniformLocation(ShaderProgID, uniformName);
    glUniform4fv(vertexColorLocation,1, newValues);
}

void new_EBO(float x, float y, float z, float r){
    unsigned int VBO;
    float object[12] = {
        x, y, z, //Bottom Left
        (x+r), y, z, //Bottom Right 
        x, (y+r), z, //Top Left
        (x+r), (y+r),z // Top Right
    };
    unsigned int drawIndices[] = {
        0,1,2,
        3,2,1
    };
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(object), object, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(drawIndices), drawIndices, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return;
}

Object* createObject(void){
    float radius = 0.01f;
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    new_EBO(0.0f, 0.0f, 0.0f, radius);
    glBindVertexArray(VAO);
    Object* newObj = (Object*)malloc(sizeof(Object));
    newObj->VAO = VAO;
    newObj->size = 1;
    return newObj;
}



void BindMultiplePixels(unsigned int* VAOs){
	float pixelRadius = 0.01f;
	glBindVertexArray(VAOs[0]);
	new_EBO(0.0f,0.0f,0.0f, pixelRadius);
	glBindVertexArray(VAOs[1]);
	new_EBO(0.5f, 0.5f, 0.0f, pixelRadius);
	return;
}