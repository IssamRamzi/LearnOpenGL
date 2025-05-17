#include "EBO.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

EBO::EBO(GLuint *indices, GLsizeiptr size){
    glGenBuffers(1, &_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

EBO::~EBO(){
    glDeleteBuffers(1, &_buffer);
}

void EBO::bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer);
}

void EBO::unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
