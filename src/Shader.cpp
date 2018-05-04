//
// Created by kurt on 18-4-16.
//

#include "Shader.h"
#include <fstream>
#include <iostream>

//int Shader::SHADER_NUM = 2;

Shader::Shader()
{
    mProgram = glCreateProgram();
    std::string vertexShader = loadShader("/home/kurt/CLionProjects/opengl2/src/res/BasicVertexShader.glsl");
    std::string fragShader = loadShader("/home/kurt/CLionProjects/opengl2/src/res/BasicFragmentShader.glsl");
    shaders[0] = createShader(vertexShader, GL_VERTEX_SHADER);
    shaders[1] = createShader(fragShader, GL_FRAGMENT_SHADER);

    for (int i = 0; i < SHADER_NUM; i++) {
        glAttachShader(mProgram, shaders[i]);
    }

    glLinkProgram(mProgram);
    if (CheckShaderError(mProgram, GL_LINK_STATUS, true, "glLinkProgram error") == GL_FALSE) {
        return;
    }

    glValidateProgram(mProgram);
    if (CheckShaderError(mProgram, GL_LINK_STATUS, true, "glValidateProgram error") == GL_FALSE) {
        return;
    }

    //this function will map shader attribute to VBO index,
    //   first parameter is Shader program
    //   second parameter VBO index in which data is set by Mesh code glEnableVertexAttribArray
    //   third parameter is name of attribute in Vertex Shader
    glBindAttribLocation(mProgram, 0, "position");
    //glBindAttribLocation(mProgram, 1, "texCord");

}

Shader::~Shader()
{
    for (int i = 0; i < SHADER_NUM; i++) {
        glDetachShader(mProgram, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(mProgram);
}

GLboolean Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) const
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
    return success;
}

GLuint Shader::createShader(const std::string shaderSource, GLuint type) const
{
    unsigned int shaderType = type;
    GLuint shader = glCreateShader(shaderType);
    if (shader == 0) {
        std::cerr << "glCreateShader failed" << ": '" << glGetError() << "'" << std::endl;
        return -1;
    }

    GLint length[1];
    length[0] = shaderSource.length();
    const GLchar * p[1];
    p[0] = shaderSource.c_str();
    glShaderSource(shader, 1, p, length);
    glCompileShader(shader);
    CheckShaderError(shader, GL_COMPILE_STATUS, false /*not program */, "shader error.");
    return shader;
}

std::string Shader::loadShader(const std::string &fileName)
{
    std::ifstream input(fileName, std::ios_base::in);
    std::string output;
    std::string line;

    char buf[1024] = {0};
    while (input.good()) {
        input.read(buf, 1024);
        output.append(buf);
    }
    std::cout << output << std::endl;
    return output;
}

void Shader::Bind()
{
    glUseProgram(mProgram);
}
