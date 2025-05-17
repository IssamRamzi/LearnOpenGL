#include "glad/glad.h"
#include "VBO.h"

class VAO
{
private:
    GLuint _buffer;
public:
    
    VAO();
    ~VAO();
    void linkVBO(VBO vbo, GLint layout);
    void bind();
    void unbind();
};
