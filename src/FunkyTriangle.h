#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"

class FunkyTriangle{
public:
    FunkyTriangle();


  public:
    void setup(ofPoint _a, ofPoint _b, ofPoint _c);
    void update(ofColor _color, float _phase);
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofColor color;
    float d;
    float factor;
    
    
    int index;
    
//    ofColor triangleColor;
    
    ofPoint a, b, c;
};
