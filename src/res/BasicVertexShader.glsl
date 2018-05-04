#version 120
attribute vec3 position;
attribute vec2 texCord;

varying vec2 texCord0;

void main() {
    gl_Position = vec4(position, 1.0);
    texCord0 = texCord;
}
