//Basic Shader info called by Shade.C

const char* Get_vertexShaderSource(void){
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main(){\n"
        "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
    return vertexShaderSource;
}

const char* Get_fragShaderSource(void){
const char* fragShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec4 uniColor;\n"
    "void main(){\n"
        "FragColor = uniColor;\n"
    "}\0";
    return fragShaderSource;
}