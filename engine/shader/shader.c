#include "shader.h"
#include "glad/glad.h"

void compile_shaders(Shader* shader, const char* vertexCode, const char* fragmentCode) {
    unsigned int vertex, fragment;
    int success = 0;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        fprintf(stderr, "%s", infoLog);
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
        fprintf(stderr, "%s", infoLog);
    }

    shader->ID = glCreateProgram();
    glAttachShader(shader->ID, vertex);
    glAttachShader(shader->ID, fragment);
    glLinkProgram(shader->ID);

    glGetProgramiv(shader->ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader->ID, 512, NULL, infoLog);
        LOGERR("ERROR::SHADER::PROGRAMM::LINKING_FAILED\n");
        fprintf(stderr, "%s", infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void loadShaders(Shader* shader, const char* vertexPath, const char* fragmentPath) {
    char* vertexCode;
    char* fragmentCode;
    
    FILE* vertexfile_ptr;
    if(fopen_s(&vertexfile_ptr, vertexPath, "r") != 0 || vertexfile_ptr == NULL) {
        LOGERR("Failed to load vertex shader file");
        exit(1);
    }

    fseek(vertexfile_ptr, 0, SEEK_END);
    uint64_t vertexSize = ftell(vertexfile_ptr);
    fseek(vertexfile_ptr, 0, SEEK_SET);

    vertexCode = (char*)malloc(vertexSize + 1);
    if(vertexCode == NULL) {
        LOGERR("Memory allocation failed for vertex shader");
        exit(1);
    }
    memset(vertexCode, 0, vertexSize + 1);
    fread(vertexCode, 1, vertexSize, vertexfile_ptr);
    vertexCode[vertexSize] = '\0';
    fclose(vertexfile_ptr);

    FILE* fragmentfile_ptr;
    if(fopen_s(&fragmentfile_ptr, fragmentPath, "r") != 0 || fragmentfile_ptr == NULL) {
        LOGERR("Failed to load fragment shader file");
        exit(1);
    }

    fseek(fragmentfile_ptr, 0, SEEK_END);
    uint64_t fragmentSize = ftell(fragmentfile_ptr);
    fseek(fragmentfile_ptr, 0, SEEK_SET);

    fragmentCode = (char*)malloc(fragmentSize + 1);
    if(fragmentCode == NULL) {
        LOGERR("Memory allocation failed for fragment shader");
        exit(1);
    }

    memset(fragmentCode, 0, fragmentSize + 1);
    fread(fragmentCode, 1, fragmentSize, fragmentfile_ptr);
    fragmentCode[fragmentSize] = '\0';
    fclose(fragmentfile_ptr);

    compile_shaders(shader, vertexCode, fragmentCode);
    free(vertexCode);
    free(fragmentCode);
}

void shader_use(Shader* shader) {
    glUseProgram(shader->ID);
}

void shader_setBool(Shader* shader, const char* name, bool value) {
    glUniform1i(glGetUniformLocation(shader->ID, name), (int)value);
}

void shader_setInt(Shader* shader, const char* name, int value) {
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void shader_setFloat(Shader* shader, const char* name, float value) {
    glUniform1f(glGetUniformLocation(shader->ID, name), value);
}

void shader_setVec2(Shader* shader, const char* name, Vec2 a) {
    glUniform2f(glGetUniformLocation(shader->ID, name), a.x, a.y);
}