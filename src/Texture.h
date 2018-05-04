//
// Created by kurt on 18-5-2.
//

#ifndef OPENGL2_TEXTURE_H
#define OPENGL2_TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>

using namespace std;

class Texture {
public:
    explicit Texture(string textureFile);

    ~Texture();

    void bind(int unit);

private:
    GLuint mTexture;
private:
    Texture(const Texture &texture) {

    }

    void operator=(const Texture &texture) {

    }
};


#endif //OPENGL2_TEXTURE_H
