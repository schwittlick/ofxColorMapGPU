#version 150

in vec2 vertexTexCoord;

uniform sampler2DRect colorTex;
uniform sampler2DRect grayTex;

out vec4 outputColor;

void main( ) {
	float x = texture( grayTex, vertexTexCoord ).r;
	vec4 finishedColor = texture( colorTex, vec2(x * 270, 0.0) );
	
	outputColor = finishedColor;
}