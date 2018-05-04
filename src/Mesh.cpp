//
// Created by kurt on 18-4-23.
//

#include <vector>

#include "Mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int numVertex) {
    mDrawCount = numVertex;

    std::vector<glm::vec3> vertexVector;
    std::vector<glm::vec2> texVector;
    vertexVector.reserve(numVertex);
    texVector.reserve(numVertex);

    for (int i = 0; i < numVertex; ++i) {
        vertexVector.push_back(vertices[i].getPos());
        texVector.push_back(vertices[i].getTex());
    }

    GLuint VAOs[1];
    glGenVertexArrays(1, VAOs);//generate a VAO
    mVertexArrayObject = VAOs[0];
    glBindVertexArray(mVertexArrayObject);//make mVertexArrayObject current VAO

    /*
     * https://paroj.github.io/gltut/Basics/Tut01%20Following%20the%20Data.html
     */
    glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);//VBO
    glBindBuffer(GL_ARRAY_BUFFER,
                 mVertexArrayBuffers[POSITION_VB]);//GL_ARRAY_BUFFER this buffer is array,  Later commands that affect to the buffer bound to GL_ARRAY_BUFFER will affect this particular object, until a new buffer object is bound to GL_ARRAY_BUFFER
    glBufferData(GL_ARRAY_BUFFER, mDrawCount * sizeof(vertexVector[0]), &vertexVector[0],
                 GL_STATIC_DRAW); //1. It allocates memory for the buffer currently bound to GL_ARRAY_BUFFER 2. The other operation that glBufferData performs is copying data from our memory array into the buffer object.

    /*
     * In code, when referring to attributes, they are always referred to by attribute index.
     * The functions glEnableVertexAttribArray, glDisableVertexAttribArray, and glVertexAttribPointer all take as
     * their first parameter an attribute index.
     * We assigned the attribute index of the position attribute to 0 in the vertex shader,
     * so the call to glEnableVertexAttribArray(0) enables the attribute index for the position attribute.
     */
    glEnableVertexAttribArray(0);//attribute index important!!!!!!!!!!!!
    /*
     * The glVertexAttribPointer function tells OpenGL all of this.
     * The third parameter specifies the base type of a value.
     * In this case, it is GL_FLOAT, which corresponds to a 32-bit floating-point value.
     * The second parameter specifies how many of these values represent a single piece of data.
     * In this case, that is 4. The fifth parameter specifies the spacing between each set of values.
     * In our case, there is no space between values, so this value is 0.
     * And the sixth parameter specifies the byte offset from the value in the buffer object is at the front,
     * which is 0 bytes from the beginning of the buffer object.
     *
     */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);



//    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[TEXTURE_VB]);
//    glBufferData(GL_ARRAY_BUFFER, mDrawCount * sizeof(texVector[0]), &texVector[0], GL_STATIC_DRAW);
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // ---------unbind VAO and VBO ------------------------------------------------
    // unbind mVertexArrayBuffers[POSITION_VB], bind buffer call is simply cleanup.
    // By binding the buffer object 0 to GL_ARRAY_BUFFER,
    // we cause the buffer object previously bound to that target to become unbound from it
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //unbind mVertexArrayObject, now mVertexArrayObject is not current VAO
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteBuffers(NUM_BUFFERS, mVertexArrayBuffers);
    glDeleteVertexArrays(1, &mVertexArrayObject);//delete VAO
}

void Mesh::Draw() {
    glBindVertexArray(mVertexArrayObject);//make mVertexArrayObject current VAO

    glDrawArrays(GL_TRIANGLES, 0,
                 mDrawCount);//he second and third parameters represent the start index and the number of indices to read from our vertex data

    glBindVertexArray(0);//unbind mVertexArrayObject, now mVertexArrayObject is not current VAO
}

Vertex::Vertex(const glm::vec3 &pos, const glm::vec2 &tex)
        : pos(pos),
          tex(tex) { // not this->pos = pos;

}


