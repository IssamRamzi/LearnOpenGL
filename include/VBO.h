#include "glad/glad.h"
#include "GLFW/glfw3.h"


class VBO
{
private:
    GLuint _buffer;

public:
    VBO(GLfloat* vertices, GLsizeiptr size);
    ~VBO();

    void bind();
    void unbind();
};
