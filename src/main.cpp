#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main() {
    Display display;

    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0)),
            Vertex(glm::vec3(0, 0.5, 0)),
            Vertex(glm::vec3(0.5, -0.5, 0))
    };
    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Shader shader;  //glCreateProgram should be call after glewInit, https://stackoverflow.com/questions/22171300/glsl-loading-core-dumped
    shader.Bind();

    float delta = 0.001;
    float r = 0;
    while (!display.isClosed()) {
        r += delta;
        if (r > 1.0f || r < 0.0f) {
            delta = -delta;
        }
        display.drawColor(1, 0.5, 0.5, .1);
        mesh.Draw();
        display.SwapBuffer();
    }
    return 0;
}
