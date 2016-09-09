#include "ofApp.h"
#include "tri.h"

float ofApp::factor;
float ofApp::spin;
float ofApp::xo;
float ofApp::yo;
float ofApp::rr;
float ofApp::r;
float ofApp::minDiam = 2;

map<int, tri> steps;

tri root;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1800, 1200);
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);

	factor = .25;
	spin = .55;
	xo = yo = 0;
	rr = r = 0;

	const int w = ofGetWidth();
	const int h = ofGetHeight();

	const int cx = w / 2;
	const int cy = h / 2;
	const int diam = min(cx, cy) / (1);

	ofSetColor(255, 63, 0, 15);

	ofSetBackgroundAuto(false);

	//root = tri::construct(diam);
	//steps.insert_or_assign(r, root);
	//ofPushMatrix();
	//ofTranslate(cx, cy);
	//draw();
	//ofPopMatrix();
    /*float x=cx, y=cy, d=diam, rotate=rr;
	while (d > 5) {
		offsets.push_back(ofVec4f(cx,cy,diam,rr));

		float d2, h, h3, w2,r2;
		const float sinRad60 = sin(ofDegToRad(60));
		//const ofColor topColor = ofColor(63, 255, 0, 13);
		//const ofColor leftColor = ofColor(193, 63, 63, 13);
		//const ofColor rightColor = ofColor(63, 63, 127, 13);

		d2 = diam / 2;
		w2 = diam + d2;
		r2 = w2 / 2;

		h = sinRad60 * diam;
		h3 = h / 3;
		r2d2h3h.push_back(ofVec4f(r2, d2, h3, h));


	}*/
}

//--------------------------------------------------------------
void ofApp::update(){
	r = r + spin;
	rr = sin(ofDegToRad(r));// fmod(r, 720)));
	xo = yo = (sin(rr));



	/*if (r < 360) {
		root = tri::reconstruct();
		steps.insert_or_assign(r, root);
	}
	else
		root = steps[(int)r % 360];*/

}
int width;
int height;


//--------------------------------------------------------------
void ofApp::draw(){
	width = ofGetWidth();
	height = ofGetHeight();

	const int cx = width / 2;
	const int cy = height / 2;
	const int diam = min(cx, cy);

	ofSetColor(255, 63, 0, 15);

	ofPushMatrix();
	ofTranslate(cx, cy);
	drawTri(0, 0, diam, rr);
	ofPopMatrix();
	
	/*string fps = ofToString(1/ofGetLastFrameTime());
	ofSetColor(255);
	ofDrawBitmapString(fps, 10, ofGetHeight() - 40);
	*/
	
}

const int opq = 31;
const float sinRad60 = sin(ofDegToRad(60));
ofColor red = ofColor(255, 63, 0, 2);
ofColor ylw = ofColor(255, 255, 0,2);

void ofApp::drawTri(float cx, float cy, float diam, float rotate)
{
/*	const ofColor topColor = ofColor(246,246,246, opq);
	const ofColor leftColor = ofColor(246,63,32, opq);
	const ofColor rightColor = ofColor(246,246,63, opq);
	const ofColor topColor = ofColor(63, 255, 0, opq);
	const ofColor leftColor = ofColor(193, 63, 63, opq);
	const ofColor rightColor = ofColor(63, 63, 127, opq);
*/
	
	/*drawCircle(-d2, h3, r2, leftColor);
	drawCircle(d2, h3, r2, rightColor);
	drawCircle(0, h3-h , r2, topColor);
	*/
	//ofSetColor(leftColor);
	//ofSetColor(topColor);
	//ofLine(0, 0, -d2, h3);
	//ofSetColor(rightColor);
	//ofLine(0, 0, d2, h3);
	//ofSetColor(topColor);
	//ofLine(0, 0, 0, h3 - h);

	float xf, yf;
	xf = cx*factor;
	yf = cy*factor;

	/*	if (cx > 0)
	ofSetColor(246,246,0,opq);
	else
	ofSetColor(255, 31, 0, opq);
	*/
	//ofSetColor(255, 255 - 255 * ((1 - cx / ofGetWidth()) + (1 - cy / ofGetHeight())/2) / 2,0,opq);
	ofSetColor(ofColor(red).lerp(ylw, 1-fmin(1, minDiam / (diam))));
	//ofLine(0, 0, xf, yf);
	ofLine(0, 0, 1, 1);


	if (diam > minDiam)
	{
		float d2, h, h3, r2, w2;

		d2 = diam / 2;
		w2 = diam + d2;
		r2 = w2 / 2;
		h = sinRad60 * diam;
		h3 = h / 3;

		ofPushMatrix();
		ofTranslate(xf, yf);
		ofRotate(rotate);

		float rf = (rotate + r)*factor;
		float xx = (cx*(1-factor) + xo*xf);
		float yy = (cy*(1-factor) + yo*yf);
		drawTri(xx - d2, yy + h3, d2,rf);
		drawTri(xx, yy + h3 - h, d2, rf);
		drawTri(xx + d2, yy + h3, d2, rf);

		ofPopMatrix();
	}

}

void ofApp::drawCircle(float cx, float cy, float r) {
	ofColor color = ofColor(63, 255, 0, 22);
	drawCircle(cx, cy, r, color);
}

void ofApp::drawCircle(float cx, float cy, float r, ofColor color)
{
	int circleSegLen = 2;
	const int seg = 2 * PI * r / circleSegLen;
	ofSetCircleResolution(seg);

	ofSetColor(color);
	ofCircle(cx, cy, r);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	const bool mouseUpdates = true;
	if (mouseUpdates)
	{
		spin = (spin + 1-2*(float)x / ofGetWidth()) / 2;
		factor = (factor + 1-2*(float)(ofGetHeight() - y) / ofGetHeight()) / 2;
	}
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
