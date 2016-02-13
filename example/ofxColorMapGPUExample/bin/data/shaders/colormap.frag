#version 150

in vec2 vertexTexCoord;

uniform sampler2DRect colorTex;
uniform sampler2DRect grayTex;
uniform int colormapWidth;

out vec4 outputColor;

void main( ) {
	float x = texture( grayTex, vertexTexCoord ).r;
	vec4 finishedColor = texture( colorTex, vec2(x * colormapWidth, 0.0) );
	
	outputColor = finishedColor;
}