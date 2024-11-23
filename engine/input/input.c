#include "input.h"

void process_input(Window* window) {
    glfwPollEvents();
    if(glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window->window, true);
    }
}