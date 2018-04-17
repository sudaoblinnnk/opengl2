//
// Created by kurt on 18-3-21.
//

#include "Display.h"
#include "Shader.h"
#include <GL/glew.h>

Display::Display() {
    cout << "Display Constructor" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 2);

    title = "hello world";

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

    SDL_GL_CreateContext(window);

    GLenum status = glewInit();

    if (status != GLEW_OK) {
        cout << "init glew failed." << endl;
    }

    Shader shader;  //glCreateProgram should be call after glewInit
    shader.Bind();
    closed = false;
}

Display::~Display() {
    cout << "Display Distructor" << std::endl;

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::SwapBuffer() {
    SDL_Event e;
    while (SDL_PollEvent(&e) && e.type == SDL_QUIT) {
        closed = true;
    }

    SDL_GL_SwapWindow(window);
}

void Display::drawColor(float r, float g, float b, float alpha) {
    glClearColor(r, g, b, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}
