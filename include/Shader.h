#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


class Shader
{
private:
    GLuint _shaderProgramID;
    std::string _vertexPath, _fragmentPath;

    std::string loadFromFile(const char* path);
public:
    Shader(std::string vertexPath, std::string fragmentPath);
    ~Shader();
    void enableShader();
    void disableShader();

    
};