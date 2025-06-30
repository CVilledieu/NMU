#include <masterheader.h>



typedef struct Object{
    float *Color_Vec4;
    float *Model_mat4;
    float *VertexObj_VAO;
}Object;




void BindObject(Object *obj){
    int ColorLoction = glGetUniformLocation(ShaderId, "uniformColor");
    glUniform4fv(ColorLoction, 1, obj->Color_Vec4);
    
    int ModelLocation = glGetUniformLocation(ShaderId, "model");
    glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, obj->Model_mat4);
    
    glBindVertexArray(*(obj->VertexObj_VAO));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

