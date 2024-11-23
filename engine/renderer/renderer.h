#pragma once
#include "core/common.h"

typedef struct render_data_t{
    float vertices[9];
} Render_data;

typedef struct render_shader_t {
    unsigned int shaderProgram;
} Shader;

typedef struct render_buffers_t {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
} RenderBuffers;

typedef struct Renderer_t {
    Render_data* render_data;
    Shader shader;
    RenderBuffers buffers;
} Renderer;

void render_init(Renderer* renderer);
void renderer_shutdown(Renderer* renderer);
void renderer_draw(Renderer* renderer);