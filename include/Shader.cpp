#include "Shader.h"
#include "Utils.h"


Shader::Shader(std::string vertexPath, std::string fragmentPath) :
    _vertexPath(vertexPath),
    _fragmentPath(fragmentPath)
{
    std::string vertexCode = Utils::loadStringFromFile(vertexPath.c_str());
    std::string fragmentCode = Utils::loadStringFromFile(fragmentPath.c_str());

    if (vertexCode.empty() || fragmentCode.empty()) {
        std::cerr << "Failed to load shader files" << std::endl;
        return;
    }
    std::cout << "Shaders Loaded Successfully !" << std::endl;

    const char* vertexShaderSource = vertexCode.c_str();
    const char* fragmentShaderSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, ' ');
        glGetShaderInfoLog(vertexShader, length, &length, &infoLog[0]);
        std::cout << "Failed to compile vertex shader: " << infoLog << std::endl;
        glDeleteShader(vertexShader);
        return;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, ' ');
        glGetShaderInfoLog(fragmentShader, length, &length, &infoLog[0]);
        std::cout << "Failed to compile fragment shader: " << infoLog << std::endl;
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return;
    }

    _shaderProgramID = glCreateProgram();
    glAttachShader(_shaderProgramID, vertexShader);
    glAttachShader(_shaderProgramID, fragmentShader);
    glLinkProgram(_shaderProgramID);

    glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetProgramiv(_shaderProgramID, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, ' ');
        glGetProgramInfoLog(_shaderProgramID, length, &length, &infoLog[0]);
        std::cout << "Failed to link shader program: " << infoLog << std::endl;
    }

    // Clean up shaders after linking
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