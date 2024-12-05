#pragma once
#include "core/common.h"
#include "math/vec2.h"

typedef struct Shader_t {
    unsigned int ID;
} Shader;

void loadShaders(Shader* shader, const char* vertexPath, const char* fragmentPath);
void shader_use(Shader* shader);
void shader_setBool(Shader* shader, const char* name, bool value);
void shader_setInt(Shader* shader, const char* name, int value);
void shader_setFloat(Shader* shader, const char* name, float value);
void shader_setVec2(Shader* shader, const char* name, Vec2 a);