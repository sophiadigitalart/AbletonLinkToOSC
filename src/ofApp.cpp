#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofAddListener(link.bpmChanged, this, &ofApp::bpmChanged);
	ofAddListener(link.numPeersChanged, this, &ofApp::numPeersChanged);

	string guiFile = "settings.xml";
	gui.setup("Parameters", guiFile);
	gui.setHeaderBackgroundColor(ofColor::darkRed);
	gui.setBorderColor(ofColor::darkRed);
	//gui.setDefaultWidth(320);

	OSCgroup.setup("OSC");
	OSCgroup.add(HostField.setup("Host ip", "localhost"));
	OSCgroup.add(oscPort.setup("Output port", 7000));
	gui.add(&OSCgroup);

	gui.loadFromFile(guiFile);
	// OSC setup  * * * * * * * * * * * * *
//oscSender.disableBroadcast();
	oscSender.setup(HostField, oscPort);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (phase != (int)link.getPhase()) {
		phase = (int)link.getPhase();
		ofxOscMessage oscMessage;
		oscMessage.setAddress("/link/");
		oscMessage.addDoubleArg(link.getBPM());
		oscMessage.addDoubleArg(link.getBeat());
		oscMessage.addDoubleArg(link.getPhase());
		oscSender.sendMessage(oscMessage);
		cout << "sending OSC: " << phase << endl;
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
	ofDrawBitmapString(ss.str(), 20, 120);
	gui.draw();
}
//--- OSC send message -----------------------------------------------------------
// Requires the address be wrapped in forward slashes: eg "/status/"
void ofApp::oscSendMsg(double message, string address)
{
	// send OSC message // oscSendMsg("no device","/status/");
	ofxOscMessage m;
	m.setAddress(address);
	m.addDoubleArg(message);
	oscSender.sendMessage(m);
}
//--------------------------------------------------------------
void ofApp::HostFieldChanged() {
	cout << "fieldChange" << endl;
	//oscSender.disableBroadcast();
	oscSender.setup(HostField, oscPort);
	cout << "updated" << endl;
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
	if (key == OF_KEY_RETURN) {
		cout << "ENTER" << endl;
		HostFieldChanged();
	}
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
