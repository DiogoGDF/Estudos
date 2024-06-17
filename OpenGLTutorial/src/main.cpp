#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(){
    std::cout << "Hello, World!" << std::endl;

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
    if (!window)
    {
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
    glViewport(0, 0, 800, 600);

    // Set the callback function for the window resize event
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Process user input
        processInput(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the front and back buffers so the window doesn't flicker
        glfwSwapBuffers(window);

        // Poll for events from windows such as key presses, mouse events, etc.
        glfwPollEvents();


    }
    glfwTerminate();

    return 0;
}

// Callback function to resize the viewport when the window is resized
void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Function to process all input from the user
void processInput(GLFWwindow *window)
{
    // Close the window when the user presses the escape key
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}