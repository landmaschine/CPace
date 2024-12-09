#pragma once
#include "core/common.h"
#include "renderer/window.h"

#include "math/vec2/vec2.h"

typedef struct Input_t {
    Vec2 vert;
    Vec2 hori;
} Input;

void process_input(Window* window, Input* input);