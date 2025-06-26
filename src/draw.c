#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <draw.h>

unsigned int *createArrayObject(float location[4]);

Object *CreateObject(float Location[4], unsigned int ShaderID){
    Object *new = malloc(sizeof(*new));
    new->VAO = createArrayObject(Location);
    new->shaderId = ShaderID;
    new->location = Location;
    return new;
}

void updateUniformColor(unsigned int ShaderProgID, const char* uniformName, float newValues[4]){
    int vertexColorLocation = glGetUniformLocation(ShaderProgID, uniformName);
    glUniform4fv(vertexColorLocation,1, newValues);
}

void setObjectColor(Object *obj, float color[4]){
    obj->colorValue = color;
}

void DrawObject(Object *obj){
    int ColorLoction = glGetUniformLocation(obj->shaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->colorValue);
    glBindVertexArray(*(obj->VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


void MoveObject(Object *obj, float *delta){
    obj->location[0] += delta[0];
    obj->location[1] += delta[1];
    obj->location[2] += delta[2];
    obj->location[3] += delta[3];
    free(obj->VAO);
    obj->VAO = createArrayObject(obj->location);
}


unsigned int *createArrayObject(float location[4]){
    unsigned int *VAO = malloc(sizeof(*VAO));
    glGenVertexArrays(1, VAO);
    glBindVertexArray(*VAO);
    float x = location[0];
    float y = location[1];
    float z = location[1];
    float r = location[3];
    float object[12] = {
        x, y, z, //Bottom Left
        (x+r), y, z, //Bottom Right 
        x, (y+r), z, //Top Left
        (x+r), (y+r),z // Top Right
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