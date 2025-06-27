#include <masterheader.h>

void DrawObjects(unsigned int ShadeId, Object **objs, int size){
    glUseProgram(ShadeId);
    for (int i = 0; i < size; i++){
        DrawObject(objs[i]);
    }
}

void DrawObject(Object *obj){
    int ColorLoction = glGetUniformLocation(ShaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->colorValue);

    //Orientate Object based on world constants for size and angle
    
    glBindVertexArray(*(obj->VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


// Target: The "world itself"
// Describes: Scales ojects based on depth
void SetProjectionMatrix(){
	glUseProgram(ShaderId);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
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

// Target: The view from the viewport / the "Camera"
// Describes: Camera Position, Orientation, and direction it is facing
// Achieved by: Transforms from world space to camera space (also known as eye space)
void SetViewMatrix(){
	glUseProgram(ShaderId);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
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

// Target: Object/Model itself. 
// Describes the object's size, orientation, and position
// Achieved by: Transforms from object's local coordinate space (model space) to world space
void SetModelMatrix(){
	glUseProgram(ShaderId);
    //Global scaling values
    //float ScreenAspect = (float)(gi_Width / gi_Height);
    //float sX = ScreenAspect / 60.0f;
    float sX = 1.0f;
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