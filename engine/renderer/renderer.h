#pragma once
#include "core/common.h"
#include "shader/shader.h"
#include "asset_manager/asset_manager.h"

typedef struct dynamic_array_t {
    void* data;
    int length;
} DynamicArray;

typedef struct render_data_t{
    DynamicArray vertices;
    DynamicArray indices;
} Render_data;

typedef struct render_buffers_t {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
} RenderBuffers;

typedef struct Renderer_t {
    Render_data* render_data;
    Shader shader;
    RenderBuffers buffers;
    Assets assets;
} Renderer;

void render_init(Renderer* renderer);
void renderer_shutdown(Renderer* renderer);
void renderer_draw(Renderer* renderer);