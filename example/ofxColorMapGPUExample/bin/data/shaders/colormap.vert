#version 150

uniform mat4 modelViewProjectionMatrix; // This is provide by openFrameworks
in vec2 texcoord; // This is provide by openFrameworks
in vec4 position; // varying is deprecated
out vec2 vertexTexCoord;

void main(){
    vertexTexCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position; // ftransform() is deprecated
}