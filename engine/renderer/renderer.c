#include "renderer.h"
#include "glad/glad.h"

void init_data(Renderer* renderer) {
    float init_vertices[12 + 12 + 8] = {
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    size_t num_vertices = ARRAYSIZE(init_vertices);
    renderer->render_data->vertices.data = (float*)malloc(num_vertices * sizeof(float));
    renderer->render_data->vertices.length = num_vertices;
    memcpy(renderer->render_data->vertices.data, init_vertices, num_vertices * sizeof(float));

    unsigned int init_indices[6] = {
        0, 1, 3,
        1, 2, 3
    };

    size_t num_indices = ARRAYSIZE(init_indices);
    renderer->render_data->indices.data = (unsigned int*)malloc(num_indices * sizeof(unsigned int));
    renderer->render_data->indices.length = num_indices;
    memcpy(renderer->render_data->indices.data, init_indices, num_indices * sizeof(unsigned int));
}

void init_buffers(Renderer* renderer) {
    glGenBuffers(1, &renderer->buffers.VBO);
    glGenBuffers(1, &renderer->buffers.EBO);

    glGenVertexArrays(1, &renderer->buffers.VAO);
    glBindVertexArray(renderer->buffers.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, renderer->buffers.VBO);
    glBufferData(GL_ARRAY_BUFFER, renderer->render_data->vertices.length * sizeof(float), renderer->render_data->vertices.data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->buffers.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, renderer->render_data->indices.length * sizeof(unsigned int), renderer->render_data->indices.data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void init_shader(Renderer* renderer) {
    loadShaders(&renderer->shader, "shaders/vertex_shader.glsl","shaders/fragment_shader.glsl");
}

void render_clear(Renderer* renderer) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void renderer_shutdown(Renderer* renderer) {
    glDeleteVertexArrays(1, &renderer->buffers.VAO);
    glDeleteBuffers(1, &renderer->buffers.VBO);
    glDeleteBuffers(1, &renderer->buffers.EBO);
    free(renderer->render_data->vertices.data);
}

void init_texture(Renderer* renderer) {
    load_texture(&renderer->assets, "assets/wall.jpg");
}

void render_init(Renderer* renderer) {
    memset(renderer, 0, sizeof(Renderer));
    renderer->render_data = (Render_data*)malloc(sizeof(Render_data));

    if(renderer == NULL || renderer->render_data == NULL) {
        LOGERR("Failed to init renderer!");
        exit(1);
        return;
    }


    init_data(renderer);
    init_buffers(renderer);
    init_shader(renderer);
    init_texture(renderer);

    fprintf(stdout, "Successfully initialized OpenGL Renderer!\n");
}

void renderer_draw(Renderer* renderer) {
    render_clear(renderer);
    shader_use(&renderer->shader);
    glBindTexture(GL_TEXTURE_2D, renderer->assets.texture);
    glBindVertexArray(renderer->buffers.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}