#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	colorMapIndex = 0;
	color.loadImage( "colormaps\\colormap" + ofToString( colorMapIndex ) + ".png" );
	gray.loadImage( "gray.png" );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	colormap.draw( gray.getTextureReference(), color.getTextureReference() );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch( key ) {
	case ' ':
		colorMapIndex += 1;
		colorMapIndex %= 16;
		color.loadImage( "colormaps\\colormap" + ofToString( colorMapIndex ) + ".png" );
		break;	
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
