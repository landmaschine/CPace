#pragma once
#include "../core/common.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct Window_t {
    GLFWwindow* window;
    uint32_t height;
    uint32_t width;
    const char* name;
} Window;

bool window_init(Window* window, uint32_t width, uint32_t height, const char* name);
void window_shutdown(Window* window);