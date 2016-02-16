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

		plane.set( planeWidth, planeHeight, 2, 2, OF_PRIMITIVE_TRIANGLES );
		plane.mapTexCoords( 0, 0, ofGetWidth(), ofGetHeight() );
	}

public:

	/*
		texture gray is being substituted by the colormaps color1&color2. these are interpolated by the normalized lerp parameter
	*/
	void draw( ofTexture & gray, ofTexture & color1, ofTexture & color2, float lerp ) {
		if( color1.getWidth() != color2.getWidth() || color1.getWidth() != color2.getWidth() ) {
			ofLogWarning() << "ofxColorMapGPU: the two color maps are not of equal size. Unwanted things may happen..";
		}

		if( lerp > 1.0 ) {
			ofLogWarning() << "ofxColorMapGPU: lerped value should be normalized. Currently it is: " << lerp;
			lerp = 1.0;
		}
		else if( lerp < 0.0 ) {
			ofLogWarning() << "ofxColorMapGPU: lerped value should be normalized. Currently it is: " << lerp;
			lerp = 0.0;
		}

		plane.setWidth( ofGetWidth() );
		plane.setHeight( ofGetHeight() );
		
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

	/*
		using only one colormap
	*/
	void draw( ofTexture & gray, ofTexture & color ) {
		draw( gray, color, color, 1.0 );
	}
};