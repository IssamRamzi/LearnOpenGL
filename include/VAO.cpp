#include "VAO.h"


VAO::VAO(){
    glGenVertexArrays(1, &_buffer);
}


VAO::~VAO(){
    glDeleteVertexArrays(1, &_buffer);
}

void VAO::linkVBO(VBO vbo, GLint layout){
    vbo.bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
}

void VAO::bind(){
    glBindVertexArray(_buffer);
}

void VAO::unbind(){
    glBindVertexArray(0);
}

