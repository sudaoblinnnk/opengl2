//
// Created by kurt on 18-4-16.
//

#ifndef OPENGL2_SHADER_H
#define OPENGL2_SHADER_H

#include <GL/glew.h>
#include <string>


class Shader {
private:
    GLuint mProgram;
    static const int SHADER_NUM = 2;
private:
    std::string loadShader(const std::string &fileName);
    GLuint createShader(const std::string shaderSource, GLuint) const;
    GLboolean CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) const;
public:
    void Bind();
    Shader();
    GLuint shaders[SHADER_NUM];
    ~Shader();
};

#endif //OPENGL2_SHADER_H
