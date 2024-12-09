#include "window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool window_init(Window* window, uint32_t width, uint32_t height, const char* name) {
    if(!glfwInit()) {
        fprintf(stderr, "Failed to init GLFW!\n");
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    memset(window, 0, sizeof(Window));

    window->width = width;
    window->height = height;
    window->name = name;
    window->window = glfwCreateWindow(window->width, window->height, window->name, NULL, NULL);
    if(!window->window) {
        window_shutdown(window);
        LOGERR("Failed to create Window!");
        return false;
    }
    glfwSetWindowSizeLimits(window->window, 800, 600, GLFW_DONT_CARE, GLFW_DONT_CARE);
    glfwMakeContextCurrent(window->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to init glad!\n");
        return false;
    }

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window->window, framebuffer_size_callback);

    fprintf(stdout, "Successfully initialized Window!\n");
    return true;
}

void window_shutdown(Window* window) {
    glfwDestroyWindow(window->window);
    memset(window, 0, sizeof(Window));
    glfwTerminate();
}

