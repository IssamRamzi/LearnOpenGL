#include "VBO.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

VBO::VBO(GLfloat *vertices, GLsizeiptr size){
    glGenBuffers(1, &_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VBO::~VBO(){
    glDeleteBuffers(1, &_buffer);
}

void VBO::bind(){
    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
}

void VBO::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
