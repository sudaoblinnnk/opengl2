#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main() {
    Display display;

    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
            Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1)),
            Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1, 0))
    };
    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    //glCreateProgram should be call after glewInit,
    //reference url : https://stackoverflow.com/questions/22171300/glsl-loading-core-dumped
    Shader shader;
    shader.Bind();

    //Texture texture("/home/kurt/CLionProjects/opengl2/src/res/texture/bricks.jpg");

    float delta = 0.001;
    float r = 0;
    while (!display.isClosed()) {
        r += delta;
        if (r > 1.0f || r < 0.0f) {
            delta = -delta;
        }
        display.drawColor(1, 0.5, 0.5, .1);
        mesh.Draw();
        //texture.bind(0);
        display.SwapBuffer();
    }
    return 0;
}
