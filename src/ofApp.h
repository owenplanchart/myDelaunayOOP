#pragma once

#include "ofMain.h"
#include "FunkyTriangle.h"


class ofApp : public ofBaseApp{
  public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    FunkyTriangle ft;
    int numOfPoints;
    vector <FunkyTriangle> fts;
    vector <ofPoint> getTriangle(int i);
    ofxDelaunay triangulation;
    bool wireFrame;
    glm::vec2 m;
    
    ofColor triangleC;
    float phase;
   
};
