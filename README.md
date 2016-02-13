# ofxColorMapGPU

This is a small utility to map grayscale textures to colormaps. It's nothing more than a GPU version of this: https://github.com/luteberget/ofxColorMap

The interesting bit is the fragment shader:
```
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
```

This has been tested on Win10/VS2015/OF0.9.0 using opengl 4.4
