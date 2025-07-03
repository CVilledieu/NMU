#ifndef MODEL_H
#define MODEL_H

typedef struct Object{
    unsigned int ID;
    struct Mesh *Mesh;
    Uniforms_Model *uniforms;
}Object;

typedef struct Uniforms_Model{
    float **Color_Vec4;
    float **Model_Mat4fv;
} Uniforms_Model;

#endif