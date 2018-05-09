//
// Created by kurt on 18-5-4.
//

#include "Transform.h"
#include <glm/gtx/transform.hpp>

Transform::Transform(const glm::vec3 &tranform = glm::vec3(),
                     const glm::vec3 &scale = glm::vec3(),
                     const glm::vec3 &rotate = glm::vec3())
        : tranform(tranform), scale(scale), rotate(rotate) {

}

glm::mat4 Transform::getModel() const {
    glm::mat4 transMatrix = glm::translate(tranform);

    glm::mat4 rotXMatrix = glm::rotate(rotate.x, glm::vec3(1, 0, 0));
    glm::mat4 rotYMatrix = glm::rotate(rotate.y, glm::vec3(0, 1, 0));
    glm::mat4 rotZMatrix = glm::rotate(rotate.z, glm::vec3(0, 0, 1));

    glm::mat4 scaleMatrix = glm::scale(scale);

    return transMatrix * rotXMatrix * rotYMatrix * rotZMatrix * scaleMatrix;
    //glm::mat4 v;
    //return v;
}
