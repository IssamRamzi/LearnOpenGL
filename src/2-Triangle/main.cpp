#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include "../../include/Shader.h"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


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

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Compile the shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    GLuint shaderProgram;
    shaderProgram = glCreateProgram(); // Creates a program and returns the ID reference to the newly created program object.

    glAttachShader(shaderProgram, vertexShader); // Now we need to attach the previously compiled shaders (Vertex) to the program object 
    glAttachShader(shaderProgram, fragmentShader); // Now we need to attach the previously compiled shaders (Fragment) to the program object

    glLinkProgram(shaderProgram); // Link the compiled shaders with glLinkProgram

    glUseProgram(shaderProgram); // Activate the shader

    // Delete the shaders we've linked, we no longer need them
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // GLfloat vertices[] = {
    //     -0.5f, -0.5f, 0.0f,
    //     0.5f, -0.5f, 0.0f,
    //     0.0f,  0.5f, 0.0f
    // };

    float vertices[] = { 
        0.5f, 0.5f, 0.0f, // top right 
        0.5f, -0.5f, 0.0f, // bottom right 
        -0.5f, -0.5f, 0.0f, // bottom left 
        -0.5f, 0.5f, 0.0f // top left 
        }; 
    unsigned int indices[] = { // note that we start from 0! 
        0, 1, 3, // first triangle 
        1, 2, 3 // second triangle 
    };


    // Buffers
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    while(!glfwWindowShouldClose(window)){
        // update
        processInput(window);


        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Background Color
        glClear(GL_COLOR_BUFFER_BIT); // Fills the buffer color with the background color

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // ============================================ //
        glfwPollEvents(); // checks if any events are triggered
        glfwSwapBuffers(window); // swaps the color buffer and shows it as the ouput in the screen
    }

    // free the buffers
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // ends glfw
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
#endif

#include "VAO.h"
#include "EBO.h"

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
}


int main(int argc, char const *argv[])
{
    
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

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout << "GLAD initialization failed";
        glfwTerminate();
        return 1;
    }

    Shader shader("../src/shaders/default.vert", "../src/shaders/default.frag");

    float vertices[] = { 
        0.5f, 0.5f, 0.0f, // top right 
        0.5f, -0.5f, 0.0f, // bottom right 
        -0.5f, -0.5f, 0.0f, // bottom left 
        -0.5f, 0.5f, 0.0f // top left 
        }; 
    unsigned int indices[] = { // note that we start from 0! 
        0, 1, 3, // first triangle 
        1, 2, 3 // second triangle 
    };

    VAO vao;
    vao.bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    vao.linkVBO(vbo, 0);
    vbo.unbind();
    ebo.unbind();
    vao.unbind();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.3, 0.2, 0.4, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.enableShader();
        vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    return 0;
}
