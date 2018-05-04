#version 120
varying vec2 texCord0;

uniform sampler2D sampler;

void main() {
    gl_FragColor = vec4(.5, 1, .8, 1);
    //gl_FragColor = texture2D(sampler, texCord0);
}
