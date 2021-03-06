//
// Created by kurt on 18-4-23.
//

#ifndef OPENGL2_MESH_H
#define OPENGL2_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h> //include opengl functions

class Vertex {
public:
    explicit Vertex(const glm::vec3 &pos, const glm::vec2 &tex);

    const glm::vec3 getPos() const {
        return pos;
    }

    const glm::vec2 getTex() const {
        return tex;
    }

private:
    glm::vec3 pos;
    glm::vec2 tex;
};

class Mesh {
public:
private:

public:

    Mesh(Vertex *vertices, unsigned int numVertex);

    void Draw();

    virtual ~Mesh();

private:
    Mesh(Mesh &) {}

    void operator=(Mesh &) {}

private:
    enum {
        POSITION_VB,
        TEXTURE_VB,
        NUM_BUFFERS
    };

    /*
     * Data Structure:
     * mVertexArrayObject reference to VAO, one VAO contains several VBOs.
     * VBO1 = mVertexArrayBuffers[POSITION_VB]
     *
     */
    GLuint mVertexArrayObject;//reference to GPU vertex arrays
    GLuint mVertexArrayBuffers[NUM_BUFFERS];//
    unsigned int mDrawCount;
};


#endif //OPENGL2_MESH_H
