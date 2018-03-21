//
// Created by kurt on 18-3-21.
//

#ifndef OPENGL2_DISPLAY_H
#define OPENGL2_DISPLAY_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

using namespace std;

class Display {
private:
    SDL_Window* window;
    string title;
public:
    Display();
    virtual ~Display();
};


#endif //OPENGL2_DISPLAY_H
