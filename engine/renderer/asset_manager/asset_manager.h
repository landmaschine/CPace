#pragma once
#include "core/common.h"

typedef struct Assets_t {
    unsigned int texture;
} Assets;

void load_texture(Assets* assets, const char* texPath);