#pragma once
#include "ofMain.h"

class ofxColorMapGPU {
public:

	ofShader colorMapShader;
	ofPlanePrimitive plane;

	ofxColorMapGPU() {
		colorMapShader.load( "shaders\\colormap" );

		int planeWidth = ofGetWidth();
		int planeHeight = ofGetHeight();
		int planeGridSize = 4;
		int planeColumns = planeWidth / planeGridSize;
		int planeRows = planeHeight / planeGridSize;

		plane.set( planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES );
		plane.mapTexCoords( 0, 0, ofGetWidth(), ofGetHeight() );
	}

public:

	void draw( ofTexture & gray, ofTexture & color1, ofTexture & color2, float lerp ) {
		if( color1.getWidth() != color2.getWidth() || color1.getWidth() != color2.getWidth() ) {
			ofLogWarning() << "ofxColorMapGPU: the two color maps are not of equal size. Unwanted things may happen..";
		}
		
		colorMapShader.begin();
		colorMapShader.setUniformTexture( "colorTex1", color1, 0 );
		colorMapShader.setUniformTexture( "colorTex2", color2, 1 );
		colorMapShader.setUniformTexture( "grayTex", gray, 2 );
		colorMapShader.setUniform1f( "lerpToToColor", lerp );
		colorMapShader.setUniform1i( "colormapWidth", color1.getWidth() );
		ofPushMatrix();

		ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
		plane.draw();
		ofPopMatrix();
		colorMapShader.end();
	}
};