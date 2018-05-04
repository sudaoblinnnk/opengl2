//
// Created by kurt on 18-5-2.
//

#include <iostream>
#include "Texture.h"
#include "stb_image.h"

Texture::Texture(string textureFile) {
    int width, height, numComp;
    void *imgData = stbi_load(textureFile.c_str(), &width, &height, &numComp, 4);
    if (imgData == NULL) {
        cerr << "load image failed." << endl;
    }
    glGenTextures(1, &mTexture);
    glBindTexture(GL_TEXTURE_2D, mTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //1 parameter should be GL_TEXTURE_2D
    //wrong code 1 parameter set mTexture, so display a dark triangle.
    //glTexImage2D(mTexture, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

    stbi_image_free(imgData);
}

Texture::~Texture() {
    glDeleteTextures(1, &mTexture);
}

void Texture::bind(int unit) {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, mTexture);
}