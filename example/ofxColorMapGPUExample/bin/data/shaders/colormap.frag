#version 150

in vec2 vertexTexCoord;

uniform sampler2DRect colorTex1;
uniform sampler2DRect colorTex2;
uniform float lerpToToColor;
uniform sampler2DRect grayTex;
uniform int colormapWidth;

out vec4 outputColor;

void main( ) {
	float x = texture( grayTex, vertexTexCoord ).r;
	vec2 samplePos = vec2(x * colormapWidth, 0.0);
	vec4 fromTexColor = texture( colorTex1, samplePos);
	vec4 toTexColor = texture( colorTex2, samplePos);
	//vec4 finishedColor = texture( colorTex,  );
	vec4 lerped = mix(fromTexColor, toTexColor, lerpToToColor);
	outputColor = lerped;
}