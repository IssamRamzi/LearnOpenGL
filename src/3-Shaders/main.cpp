// #include "glad/glad.h"
// #include "GLFW/glfw3.h"

// #include <iostream>


// void processInput(GLFWwindow *w);


// int main(int argc, char const *argv[])
// {
//     // init
//     if(!glfwInit()){
//         std::cout << "ERROR Loading GLFW" << std::endl;
//         return 1;
//     }

//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

//     GLFWwindow *window = glfwCreateWindow(800, 600, "Shaders", NULL, NULL);
//     if(window == NULL){
//         std::cout << "ERROR Creating the window" << std::endl;
//         return 1;
//     }

//     glfwMakeContextCurrent(window);

//     while (!glfwWindowShouldClose(window))
//     {
//         processInput(window);

//         glfwPollEvents();
//         glfwSwapBuffers(window);
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
    

//     return 0;
// }


// void processInput(GLFWwindow *window){
//     if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
//         glfwSetWindowShouldClose(window, 1);
//     }
// }