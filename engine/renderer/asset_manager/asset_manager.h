#pragma once
#include "core/common.h"

typedef struct Assets_t {
    unsigned int texture;
    int64_t width;
    int64_t height;
} Assets;

void load_texture(Assets* assets, const char* texPath);