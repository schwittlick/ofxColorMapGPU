#include "ofMain.h"
#include "ofApp.h"

#include "ofGlProgrammableRenderer.h"
//========================================================================
int main( ){
	ofGLFWWindowSettings windowSettings;
	windowSettings.setGLVersion( 4, 4 );
	windowSettings.width = 270;
	windowSettings.height = 270;
	windowSettings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow( windowSettings );
	std::shared_ptr<ofApp> colorMapApp( new ofApp() );
	ofRunApp( window, colorMapApp );
	ofRunMainLoop();
}
