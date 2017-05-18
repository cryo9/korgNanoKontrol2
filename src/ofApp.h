#pragma once

#include "ofMain.h"
#include "korg.h"

class ofApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();

	Korg korg;
};
