#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <sstream>
#include <streambuf>
#include <string>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
std::string loadShaderSource(const char* filename);

int main() {
    std::cout << "Hello, World!" << std::endl;

    int success;
    char infoLog[512];

    glfwInit();

    // Set the OpenGL version to 3.3
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);

    // for Mac OS X
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Set the OpenGL profile to core
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Tutorial", NULL, NULL);
    if (!window) {
        fprintf(stderr, "*** ERROR OPENING WINDOW\n");
        glfwTerminate();
        return 1;
    }
    // Bring the new window to the foreground (focus)
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed no init GLEW." << std::endl;
        return EXIT_FAILURE;
    }

    // Set the OpenGL viewport to the whole window
    glViewport(0, 0, 800*2, 600*2);

    // Set the callback function for the window resize event
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

    // shaders

    // compile vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // load shader source
    std::string vertexShaderSource = loadShaderSource("../assets/vertex_core.glsl");
    const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
    // attach shader source to shader object
    glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL);
    // compile shader
    glCompileShader(vertexShader);

    // check for shader compile errors
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // compile fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // load shader source
    std::string fragmentShaderSource = loadShaderSource("../assets/fragment_core.glsl");
    const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
    // attach shader source to shader object
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
    // compile shader
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    // attach shaders to program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // link shaders
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // vertices
    float vertices[] = {
        // positions
        -0.5f, -0.5f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, // top
        0.5f, -0.5f, 0.0f, // bottom right
    };

    // VAO, VBO
    unsigned int VAO, VBO;
    // generate VAO
    glGenVertexArrays(1, &VAO);
    // generate VBO
    glGenBuffers(1, &VBO);

    // bind VAO
    glBindVertexArray(VAO);

    // bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process user input
        processInput(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw shapes
        glBindVertexArray(VAO);
        glUseProgram(shaderProgram);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap the front and back buffers so the window doesn't flicker
        glfwSwapBuffers(window);

        // Poll for events from windows such as key presses, mouse events, etc.
        glfwPollEvents();

    }
    glfwTerminate();

    return 0;
}

// Callback function to resize the viewport when the window is resized
void frame_buffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width*2, height*2);
}

// Function to process all input from the user
void processInput(GLFWwindow *window) {
    // Close the window when the user presses the escape key
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

std::string loadShaderSource(const char* filename) {
    std::ifstream file;
    std::stringstream buf;
    
    std::string ret = "";

    file.open(filename);

    if (file.is_open()) {
        buf << file.rdbuf();
        ret = buf.str();
    } else {
        std::cout << "Error loading shader source from file: " << filename << std::endl;
    }

    file.close();

    return ret;
}