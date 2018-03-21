//
// Created by kurt on 18-3-21.
//

#include "Display.h"

Display::Display() {
    cout << "Display Constructor" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    title = "display";
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(window);
}

Display::~Display() {
    cout << "Display Distructor" << std::endl;
    SDL_Quit();
}
