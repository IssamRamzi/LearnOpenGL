#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

const int WIDTH = 800, HEIGHT = 600;

void processInput(GLFWwindow *window);

int main()
{
    // Init
    glfwInit();

    // Config
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);

    // Checks if it was properly done
    if(window == NULL){
        std::cout << "Window initialization failed";
        glfwTerminate();
        return 1;
    }

    // Make the window as the current context
    glfwMakeContextCurrent(window);

    // Load GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout << "GLAD initialization failed";
        glfwTerminate();
        return 1;
    }

    // Set The Viewport
    glViewport(0, 0, WIDTH, HEIGHT);

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    GLuint VBO;
    glGenBuffers(1, &VBO); // has a unique ID, so we can generate one with a buffer ID using the glGenBuffers
    // OpenGL has many buffer types and the one needed for vertices is GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  

    // Send the data to the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    

    while(!glfwWindowShouldClose(window)){
        // update
        processInput(window);


        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Background Color
        glClear(GL_COLOR_BUFFER_BIT); // Fills the buffer color with the background color

        // ============================================ //
        glfwPollEvents(); // checks if any events are triggered
        glfwSwapBuffers(window); // swaps the color buffer and shows it as the ouput in the screen
    }

    // ends glfw
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
}