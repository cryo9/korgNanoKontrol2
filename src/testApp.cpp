#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(235, 235, 235);
	
	korg.setup();
}

//--------------------------------------------------------------
void testApp::update() {
	korg.update();
}

//--------------------------------------------------------------
void testApp::draw() {   
	korg.draw();
}
