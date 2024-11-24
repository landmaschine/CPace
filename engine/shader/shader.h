#pragma once
#include "core/common.h"

typedef struct Shader_t {
    unsigned int ID;
} Shader;

void loadShaders(Shader* shader, const char* vertexPath, const char* fragmentPath);
void shader_use(Shader* shader);
void shader_setBool(Shader* shader, const char* name, bool value);
void shader_setInt(Shader* shader, const char* name, int value);
void shader_setFloat(Shader* shader, const char* name, float value);