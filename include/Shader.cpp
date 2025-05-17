#include "Shader.h"
#include "Utils.h"


Shader::Shader(std::string vertexPath, std::string fragmentPath) :
    _vertexPath(vertexPath),
    _fragmentPath(fragmentPath)
{
    
    const char* vertexShaderSource = Utils::loadStringFromFile(vertexPath.c_str()).c_str();
    const char* fragmentShaderSource = Utils::loadStringFromFile(fragmentPath.c_str()).c_str();

    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
    glCompileShader(vertexShader);

    GLint success = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
        char *infoLog = (char *)malloc(length);
        glGetShaderInfoLog(vertexShader, length, &length, &infoLog[0]);
        std::cout << "Failed to compile vertex shader : " <<  infoLog << std::endl;
        glDeleteShader(vertexShader);
        return;
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
        char *infoLog = (char *)malloc(length);
        glGetShaderInfoLog(vertexShader, length, &length, &infoLog[0]);
        std::cout << "Failed to compile vertex shader : " <<  infoLog << std::endl;
        glDeleteShader(vertexShader);
        return;
    }

    _shaderProgramID = glCreateProgram();
    glAttachShader(_shaderProgramID, vertexShader);
    glAttachShader(_shaderProgramID, fragmentShader);

    glLinkProgram(_shaderProgramID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

Shader::~Shader(){
    glDeleteProgram(_shaderProgramID);
}

void Shader::enableShader(){
    glUseProgram(_shaderProgramID);
}

void Shader::disableShader(){
    glUseProgram(0);
}

GLint Shader::getUniformLoc(const GLchar *name) {
    return glGetUniformLocation(_shaderProgramID, name);
}

void Shader::setUniformMat4(const GLchar *name, Matrix4<float> mat) {
    glUniformMatrix4fv(glGetUniformLocation(_shaderProgramID, name), 1, GL_FALSE, mat.data);
}

void Shader::setUniform1f(const GLchar* name, float val){
    glUniform1f(getUniformLoc(name), val);
}

void Shader::setUniform2f(const GLchar* name, Vec2<float> vec){
    glUniform2f(glGetUniformLocation(_shaderProgramID, name), vec.x, vec.y);
}

void Shader::setUniform3f(const GLchar* name, Vec3<float> vec){
    glUniform3f(getUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::setUniform4f(const GLchar* name, Vec4<float> vec){
    glUniform4f(getUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}

void Shader::setUniform1i(const GLchar* name, int val){
    glUniform1i(getUniformLoc(name), val);
}

void Shader::setUniform2i(const GLchar* name, Vec2<int> vec){
    glUniform2i(getUniformLoc(name), vec.x, vec.y);
}

void Shader::setUniform3i(const GLchar* name, Vec3<int> vec){
    glUniform3i(getUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::setUniform4i(const GLchar* name, Vec4<int> vec){
    glUniform4i(getUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}