#include "renderer.h"
#include "glad/glad.h"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
    
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";




void shader_use(Shader* shader) {
    glUseProgram(shader->shaderProgram);
}

void init_render_data(Renderer* renderer) {
    float init_vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    for(size_t i = 0; i < (sizeof(init_vertices) / sizeof(float)); ++i) {
        renderer->render_data->vertices[i] = init_vertices[i];
    }
}

void render_init_buffers(Renderer* renderer) {
    glGenBuffers(1, &renderer->buffers.VBO);
    glGenVertexArrays(1, &renderer->buffers.VAO);

    glBindVertexArray(renderer->buffers.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, renderer->buffers.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(renderer->render_data->vertices), renderer->render_data->vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}


void shader_compile(Shader* shader, const char* vertexShaderSource, const char* fragmentShaderSource) {
    unsigned int vertexShader;
    unsigned int fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success = 0;
    char* infoLog = (char*)malloc(sizeof(char) * 512);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS ,&success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        fprintf(stderr, "%s\n", infoLog);
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        fprintf(stderr, "%s\n", infoLog);
    } 
    
    shader->shaderProgram = glCreateProgram();

    glAttachShader(shader->shaderProgram, vertexShader);
    glAttachShader(shader->shaderProgram, fragmentShader);
    glLinkProgram(shader->shaderProgram);

    glGetProgramiv(shader->shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader->shaderProgram, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::PROGRAMM::LINK_FAILED");
        fprintf(stderr, "%s\n", infoLog);
    }

    free(infoLog);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void render_init_shader(Renderer* renderer) {
    shader_compile(&renderer->shader, vertexShaderSource, fragmentShaderSource);
}

void render_clear(Renderer* renderer) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void renderer_shutdown(Renderer* renderer) {
    free(renderer->render_data->vertices);
}

void render_init(Renderer* renderer) {
    memset(renderer, 0, sizeof(Renderer));
    renderer->render_data = (Render_data*)malloc(sizeof(Render_data));

    if(renderer == NULL || renderer->render_data == NULL) {
        LOGERR("Failed to init renderer!");
        exit(1);
        return;
    }

    init_render_data(renderer);
    render_init_buffers(renderer);
    render_init_shader(renderer);

    fprintf(stdout, "Successfully initialized OpenGL Renderer!\n");
}

void renderer_draw(Renderer* renderer) {
    render_clear(renderer);
    shader_use(&renderer->shader);
    glBindVertexArray(renderer->buffers.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}