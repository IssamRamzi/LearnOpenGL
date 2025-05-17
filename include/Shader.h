#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "CrockMath.h"


class Shader
{
private:
    GLuint _shaderProgramID;
    std::string _vertexPath, _fragmentPath;
public:
    Shader(std::string vertexPath, std::string fragmentPath);
    ~Shader();
    void enableShader();
    void disableShader();
    inline GLuint getShaderProgram(){return _shaderProgramID;}


    GLint getUniformLoc(const GLchar *name);

    void setUniformMat4(const GLchar *name, Matrix4<float> mat);
    void setUniform1f(const GLchar* name, float val);
    void setUniform2f(const GLchar* name, Vec2<float> vec);
    void setUniform3f(const GLchar* name, Vec3<float> vec);
    void setUniform4f(const GLchar* name, Vec4<float> vec);
    void setUniform1i(const GLchar* name, int val);
    void setUniform2i(const GLchar* name, Vec2<int> vec);
    void setUniform3i(const GLchar* name, Vec3<int> vec);
    void setUniform4i(const GLchar* name, Vec4<int> vec);
};