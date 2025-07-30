#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int width = 800;
const unsigned int height = 600;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);  
void processInput(GLFWwindow *window);

int main (int argc, char *argv[]) {
    std::cout << "hello world" << std::endl;

    // configure glfw with options
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create the actual window with glfw
    GLFWwindow* window = glfwCreateWindow(width, height, "Learning to use the GPU", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create the GLFW window" << std::endl;
        return -1;
    }

    // create an opengl context in that window
    glfwMakeContextCurrent(window);
    // allows the resizing of the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // loads the opengl function pointers from the GPU driver with GLAD 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // creates the actual render window in the glfw window
    glViewport(0, 0, width, height);
    
    // render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    int result = glfwWindowShouldClose(window);
    std::cout << "Window has been closed" << std::endl;
    std::cout << "value: " << result << std::endl;

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

