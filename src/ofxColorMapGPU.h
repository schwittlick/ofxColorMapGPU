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
	void draw( ofTexture & gray, ofTexture & color ) {
		colorMapShader.begin();
		colorMapShader.setUniformTexture( "colorTex", color, 0 );
		colorMapShader.setUniformTexture( "grayTex", gray, 1 );
		ofPushMatrix();

		ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
		plane.draw();
		ofPopMatrix();
		colorMapShader.end();
	}
};