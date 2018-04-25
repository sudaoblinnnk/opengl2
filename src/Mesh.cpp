//
// Created by kurt on 18-4-23.
//

#include "Mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int numVertex) {
    mDrawCount = numVertex;

    GLuint VAOs[1];
    glGenVertexArrays(1, VAOs);//generate a VAO
    mVertexArrayObject = VAOs[0];
    glBindVertexArray(mVertexArrayObject);//make mVertexArrayObject current VAO

    glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);//VBO
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);//GL_ARRAY_BUFFER this buffer is array
    glBufferData(GL_ARRAY_BUFFER, mDrawCount * sizeof(struct Vertex), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);//unbind mVertexArrayBuffers[POSITION_VB]
    glBindVertexArray(0);//unbind mVertexArrayObject, now mVertexArrayObject is not current VAO
}

Mesh::~Mesh() {
    glDeleteBuffers(NUM_BUFFERS, mVertexArrayBuffers);
    glDeleteVertexArrays(1, &mVertexArrayObject);//delete VAO
}

void Mesh::Draw() {
    glBindVertexArray(mVertexArrayObject);//make mVertexArrayObject current VAO

    glDrawArrays(GL_TRIANGLES, 0, mDrawCount);

    glBindVertexArray(0);//unbind mVertexArrayObject, now mVertexArrayObject is not current VAO
}

Vertex::Vertex(const glm::vec3 &pos) : pos(pos) { // not this->pos = pos;

}
