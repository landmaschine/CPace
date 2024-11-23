#pragma once
#include "common.h"
#include "renderer/window.h"
#include "renderer/renderer.h"
#include "input/input.h"

typedef struct Engine_t {
    Window window;
    Renderer renderer;
} Engine;

void run(Engine* engine);