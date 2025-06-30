#include <masterheader.h>



typedef struct Object{
    float *Color_Vec4;
    float *Model_mat4;
    float *VertexObj_VAO;
}Object;




void DrawObject(Object *obj){
    int ColorLoction = glGetUniformLocation(ShaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->colorValue);

 
    
    glBindVertexArray(*(obj->VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

