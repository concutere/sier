#pragma once

#include "ofMain.h"
#include "tri.h"

class ofApp : public ofBaseApp{

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

		void drawTri(float cx, float cy, float diam, float rotate);
		void drawCircle(float cx, float cy, float r);
		void drawCircle(float cx, float cy, float r, ofColor color);

		static float factor, xo, yo, spin, rr, r, minDiam;

};
