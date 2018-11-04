#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofAddListener(link.bpmChanged, this, &ofApp::bpmChanged);
	ofAddListener(link.numPeersChanged, this, &ofApp::numPeersChanged);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (tempo != link.getBPM()) {
		tempo = link.getBPM();
		//client.send("{\"cmd\" :[{\"type\" : 2,\"tempo\" : " + ofToString(link.tempo()) + "}]}");
		cout << "sending tempo change" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	float x = ofGetWidth() * link.getPhase() / link.getQuantum();

	ofSetColor(255, 0, 0);
	ofDrawLine(x, 0, x, ofGetHeight());

	std::stringstream ss("");
	ss
		<< "bpm:   " << link.getBPM() << std::endl
		<< "beat:  " << link.getBeat() << std::endl
		<< "phase: " << link.getPhase() << std::endl
		<< "peers: " << link.getNumPeers() << std::endl;

	ofSetColor(255);
	ofDrawBitmapString(ss.str(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		if (20 < link.getBPM()) link.setBPM(link.getBPM() - 1.0);
	}
	else if (key == OF_KEY_RIGHT) {
		link.setBPM(link.getBPM() + 1.0);
	}
	else if (key == 'b') {
		link.setBeat(0.0);
	}
	else if (key == 'B') {
		link.setBeatForce(0.0);
	}
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
