#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(235, 235, 235);
	
	korg.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
	korg.update();
}

//--------------------------------------------------------------
void ofApp::draw() {   
	korg.draw();
}

