#include "glad/glad.h"
#include "GLFW/glfw3.h"


class EBO
{
private:
    GLuint _buffer;

public:
    EBO(GLuint* indices, GLsizeiptr size);
    ~EBO();

    void bind();
    void unbind();
};
