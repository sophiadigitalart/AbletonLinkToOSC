#pragma once

#include "ofMain.h"
#include "ofxAbletonLink.h"
#include "ofxOsc.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	void bpmChanged(double &bpm) {
		ofLogNotice("bpmChanged") << bpm;
	}

	void numPeersChanged(std::size_t &peers) {
		ofLogNotice("numPeersChanged") << peers;
	}
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
private:
		ofxAbletonLink link;
		double tempo;
		void HostFieldChanged();
		// OSC
		ofxOscSender oscSender;
		void oscSendMsg(double message, std::string address);

		// GUI
		ofxPanel gui;

		ofxGuiGroup OSCgroup;
		ofxIntField oscPort; // Output
		ofxIntField oscPortIn;
		ofxTextField HostField;

};
