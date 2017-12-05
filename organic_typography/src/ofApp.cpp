#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    font.load("arial", 100, false, false, true);  //function to load the font
    sentence = "Goldsmiths";
    stringPoints = getStringPoints(sentence, 100);   //stringPoints contains now the points that make up the word "Goldsmiths"

    // YOUR CODE STARTS HERE

    for (int i=0; i<stringPoints.size(); i++) {
      noiseSeeds.push_back(ofRandom(1000));
    }

    // YOUR CODE ENDS HERE

}

//--------------------------------------------------------------
void ofApp::update(){

    // YOUR CODE STARTS HERE


    // YOUR CODE ENDS HERE
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate((ofGetWidth() - font.stringWidth(sentence))/2, 250);

    // YOU CODE STARTS HERE





    float noiseSize = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 40);

    for (int i=0; i < stringPoints.size(); i++) {

      float x = ofSignedNoise(noiseSeeds[i]) * noiseSize;
      float y = ofSignedNoise(noiseSeeds[i] + 55) * noiseSize;

      ofPoint offset = ofPoint(x, y);

      ofPoint newPoint = stringPoints[i] + offset;

      // radius between -6 and 6

      float pointSize = ofSignedNoise(noiseSeeds[i]) * 6;

      ofColor col1 = ofColor::paleGreen;
      ofColor col2 = ofColor::paleTurquoise;
      ofColor color = col1.getLerped(col2, ofNoise(noiseSeeds[i]));

   ofSetColor(color);

      ofDrawCircle(newPoint, pointSize);

        
    
      noiseSeeds[i] = noiseSeeds[i] + 0.01;
    }

    // END OF YOUR CODE

    ofPopMatrix();
}

//--------------------------------------------------------------
vector <ofPoint> ofApp::getStringPoints(string s, int numOfSamples){
    vector <ofPoint> stringPoints;
    // get the string as paths
    vector < ofTTFCharacter > paths = font.getStringAsPoints(s);

    //find the biggest character in terms of perimeter (used for uniform resampling)
    int maxPerimeter = 0;
    for (int i = 0; i < paths.size(); i++){
       vector <ofPolyline> polylines = paths[i].getOutline();
       for (int j = 0; j < polylines.size(); j++){
           if (polylines[j].getPerimeter()>maxPerimeter) maxPerimeter = polylines[j].getPerimeter();
       }
    }
    // for every character, get its path
    for (int i = 0; i < paths.size(); i++){
        // for every character break it out to polylines
        vector <ofPolyline> polylines = paths[i].getOutline();
        // for every polyline, resample it
        for (int j = 0; j < polylines.size(); j++){
            int numOfPoints = ofMap(polylines[j].getPerimeter(), 0, maxPerimeter, 0, numOfSamples, true);
            for (int i=0; i<numOfPoints; i++){
                 stringPoints.push_back(ofPoint(polylines[j].getPointAtPercent(float(i+1)/numOfPoints)));
            }
        }
      }
     return stringPoints;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
