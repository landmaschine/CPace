#include "asset_manager.h"
#define STB_IMAGE_IMPLEMENTATION 
#include "stb/stb_image.h"
#include "glad/glad.h"

//No Jpg only PNG!
void load_texture(Assets* assets, const char* texPath) {
    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &assets->texture);
    glBindTexture(GL_TEXTURE_2D, assets->texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(texPath, &width, &height, &nrChannels, 0);
    if(data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        assets->height = height;
        assets->width = width;
    } else {
        LOGERR("Failed to load texture");
    }

    stbi_image_free(data);
}