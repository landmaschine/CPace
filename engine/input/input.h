#pragma once
#include "core/common.h"
#include "renderer/window.h"


typedef struct Input_t {
    glm::vec2 vert;
    glm::vec2 hori;
} Input;

void process_input(Window* window, Input* input);