#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

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

    Texture texture("/home/kurt/CLionProjects/opengl2/src/res/texture/bricks.jpg");
    glm::vec3 pos;
    glm::vec3 scale(1, 1, 1);
    glm::vec3 rotate(0, 0, 0);

    Transform t1(pos, scale, rotate);

    float step = 0.01;
    float delta = 0.001;
    float r = 0;
    while (!display.isClosed()) {
        r += delta;
        if (r > 1.0f || r < 0.0f) {
            delta = -delta;
        }
        display.drawColor(1, 0.5, 0.5, .1);
        mesh.Draw();
        texture.bind(0);

        t1.getTranform().x = sin(step);
        t1.getTranform().y = cos(step);
        t1.setRotate(glm::vec3(0, 0, step));
        shader.update(t1);
        step += 0.01;

        display.SwapBuffer();

    }
    return 0;
}
