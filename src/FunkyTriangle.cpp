#include "FunkyTriangle.h"

//--------------------------------------------------------------
FunkyTriangle::FunkyTriangle(){
  

}
void FunkyTriangle::setup(ofPoint _a, ofPoint _b, ofPoint _c){

    a = _a;
    b = _b;
    c = _c;

}



//--------------------------------------------------------------
void FunkyTriangle::update(ofColor _color, float _colourPhase){

    color = _color;
    color.r = _colourPhase; // this makes the red value phase in and out
    d = abs(sin(ofDegToRad(ofGetFrameNum())))+.6; // this makes it go from dark to bright
    color *= d;

}
//--------------------------------------------------------------
void FunkyTriangle::draw(){

    ofFill();
    ofDrawTriangle(a, b, c);
    ofSetColor(color);

        // use this point to draw a wireframe
    ofPushStyle();
    ofNoFill();
    ofSetColor(255,0,100);
    ofDrawTriangle(a, b, c);
    ofPopStyle();
}

//--------------------------------------------------------------
// custom function that takes an index and returns the coordinates of the triangle we refer to


//--------------------------------------------------------------
void FunkyTriangle::keyPressed(int key){

}

//--------------------------------------------------------------
void FunkyTriangle::keyReleased(int key){

}

//--------------------------------------------------------------
void FunkyTriangle::mouseMoved(int x, int y){

}
//--------------------------------------------------------------
void FunkyTriangle::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void FunkyTriangle::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void FunkyTriangle::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void FunkyTriangle::windowResized(int w, int h){

}

//--------------------------------------------------------------
void FunkyTriangle::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void FunkyTriangle::dragEvent(ofDragInfo dragInfo){

}
