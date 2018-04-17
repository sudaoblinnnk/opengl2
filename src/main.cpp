#include <iostream>
#include "Display.h"
#include "Shader.h"

int main() {
    Display display;

    float delta = 0.001;
    float r = 0;
    while (!display.isClosed()) {
        r += delta;
        if (r > 1.0f || r < 0.0f) {
            delta = -delta;
        }
        display.drawColor(1, 0.9, 0.5, .1);
        display.SwapBuffer();
    }
    return 0;
}
