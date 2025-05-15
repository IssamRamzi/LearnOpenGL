#include "Shader.h"

Shader::Shader(std::string vertexPath, std::string fragmentPath) :
    _vertexPath(vertexPath),
    _fragmentPath(fragmentPath)
{
    const char* vertexShaderSource = loadFromFile(vertexPath.c_str()).c_str();
    const char* fragmentShaderSource = loadFromFile(fragmentPath.c_str()).c_str();

    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);
    glCompileShader(fragmentShader);

    _shaderProgramID = glCreateProgram();
    glAttachShader(_shaderProgramID, vertexShader);
    glAttachShader(_shaderProgramID, fragmentShader);

    glLinkProgram(_shaderProgramID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::enableShader(){
    glUseProgram(_shaderProgramID);
}

void Shader::disableShader(){
    glUseProgram(0);
}

std::string Shader::loadFromFile(const char* path){
    FILE* file;
    file = fopen(path, "rb");
    std::string content;
    char c;
    while(c = fgetc(file) != EOF){
        content.push_back(c);
    }   
    fclose(file);
    return content.c_str();
}

