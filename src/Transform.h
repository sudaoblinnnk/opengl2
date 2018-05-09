//
// Created by kurt on 18-5-4.
//

#ifndef OPENGL2_TRANSFORM_H
#define OPENGL2_TRANSFORM_H

#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

class Transform {
public:
    Transform(const vec3 &, const vec3 &, const vec3 &);

    vec3 &getTranform() {
        return tranform;
    }

    void setTranform(const vec3 &tranform) {
        Transform::tranform = tranform;
    }

    vec3 &getScale() {
        return scale;
    }

    void setScale(const vec3 &scale) {
        Transform::scale = scale;
    }

    vec3 &getRotate() {
        return rotate;
    }

    void setRotate(const vec3 &rotate) {
        Transform::rotate = rotate;
    }

    glm::mat4 getModel() const;

private:

    vec3 tranform;
    vec3 scale;
    vec3 rotate;

private:
    //Transform(const Transform &) {}
    //Transform() {}
    void operator=(const Transform &) {}
};


#endif //OPENGL2_TRANSFORM_H
