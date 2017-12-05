#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
        float width;
        float height;
    
        float maxRGB;
    
        ofVideoGrabber video;
    
};
