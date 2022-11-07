#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(125);
    ofSetFrameRate(60);
    ofSetLineWidth(3);
    wireFrame = 0;
    
    numOfPoints = 15;

    for(int i =0; i< numOfPoints; i++){
        m = glm::vec2(ofRandomWidth(), ofRandomHeight());
        triangulation.addPoint(m);
        }
    triangulation.triangulate();

    // loop over the triangles to give funky triangles our coordinates
         for (int g=0; g<triangulation.getNumTriangles(); g++){
        vector <ofPoint> pts = getTriangle(g);
        ft.setup(pts[0], pts[1], pts[2]); // pay attention to the index beginning at 0
        fts.push_back(ft);// pushing back the funky triangle into many triangle objects
    }
}
//--------------------------------------------------------------
void ofApp::update(){
  
    for (int g=0; g<fts.size(); g++){ // loop over the triangles
        phase = ofMap(g, 0, triangulation.getNumTriangles(), 0, 255); //using getNumTriangles instead fts.size() works much better.

//        phase = ofRandom( 0, 255);

        fts[g].update(triangleC, phase);
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int g=0 ; g<fts.size(); g++){ // loop over the triangles
        fts[g].draw();
    }
    if (wireFrame){
        ofPushStyle();
        ofNoFill();
        ofSetColor(0);
        triangulation.triangleMesh.drawWireframe();
        ofPopStyle();
    }
}
// custom function that takes an index and returns the coordinates of the triangle we refer to
vector <ofPoint> ofApp::getTriangle(int i){
    int pA = triangulation.triangleMesh.getIndex(i*3);
    int pB = triangulation.triangleMesh.getIndex(i*3+1);
    int pC = triangulation.triangleMesh.getIndex(i*3+2);
    
    ofPoint pointA = triangulation.triangleMesh.getVertex(pA);
    ofPoint pointB = triangulation.triangleMesh.getVertex(pB);
    ofPoint pointC = triangulation.triangleMesh.getVertex(pC);
    
    vector <ofPoint> points;
    points.push_back(pointA);
    points.push_back(pointB);
    points.push_back(pointC);
    return points;
}
void ofApp::keyPressed(int key){
    
    int lastPoint;
    
    if(key == 't') {
        
        triangulation.addPoint(glm::vec2(ofRandomWidth(), ofRandomHeight()));
        triangulation.triangulate(); // calculate the triangulation!
        for (int g=0; g<triangulation.getNumTriangles(); g++){
            vector <ofPoint> pts = getTriangle(g);
            ft.setup(pts[0], pts[1], pts[2]); // pay attention to the index beginning at 0
            fts.push_back(ft);
        }
//        phase = 0;
//        update();
//        draw();
        
        int lastPoint;
        lastPoint = triangulation.getNumPoints();
        cout << lastPoint << endl;
    }
    
    if(key == 'c') {
//        lastPoint = triangulation.getNumPoints();
//        cout << lastPoint << endl;
//        triangulation.removePointAtIndex(lastPoint-1);
//         // calculate the triangulation!
//        triangulation.triangulate();
//        for (int g=triangulation.getNumTriangles(); g>0; g--){
//            vector <ofPoint> pts = getTriangle(g);
//            ft.setup(pts[0], pts[1], pts[2]); // pay attention to the index beginning at 0
//            fts.push_back(ft);
//        }
    }
    if(key == 'r') {
        triangulation.reset();
//        triangulation.triangulate();
       for (int g=0; g<triangulation.getNumTriangles(); g++){
            vector <ofPoint> pts = getTriangle(g);
            ft.setup(pts[0], pts[1], pts[2]); // pay attention to the index beginning at 0
            fts.push_back(ft);
        }
        // this allows you to get the
    }
    if(key == 'w'){
        wireFrame =! wireFrame;
    }
    if(key == 'q'){
        triangulation.addPoint(glm::vec2(0,0));
        triangulation.addPoint(glm::vec2(ofGetWidth(), 0));
        triangulation.addPoint(glm::vec2(0, ofGetHeight()));
        triangulation.addPoint(glm::vec2(ofGetWidth(), ofGetHeight()));
        triangulation.triangulate();
    }
    for (int g=0; g<triangulation.getNumTriangles(); g++){
        vector <ofPoint> pts = getTriangle(g);
        ft.setup(pts[0], pts[1], pts[2]); // pay attention to the index beginning at 0
        fts.push_back(ft);
    }

}

