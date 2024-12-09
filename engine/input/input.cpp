#include "input.h"

void process_input(Window* window, Input* input) {
    glfwPollEvents();
    if(glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window->window, true);
    }

    if(glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS) {
        input->vert.x += 10.f;
    }

    if(glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS) {
        input->vert.y -= 10.f;
    }

    if(glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS) {
        input->vert.y += 10.f;
    }

    if(glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS) {
        input->vert.y += 10.f;
    }
}