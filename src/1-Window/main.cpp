#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

const int WIDTH = 800, HEIGHT = 600;

void processInput(GLFWwindow *window);

#if 0

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

#endif