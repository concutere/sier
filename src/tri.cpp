#include "tri.h"
#include "ofMain.h"

tri::tri()
{
}


tri::~tri()
{
}

float tri::factor;
float tri::spin;
float tri::xo;
float tri::yo;
float tri::rr;
float tri::r;
float tri::maxDiam;

tri tri::reconstruct() {
	return createTri(0, 0, maxDiam, rr);
}
tri tri::construct(float diam)
{
	maxDiam = diam;
	r = rr = 0;
	factor = .25;
	spin = .55;
	xo = yo = 0;

	return createTri(0, 0, diam, rr);
}

tri tri::createTri(float cx, float cy, float diam, float rotate)
{
	tri created = tri();
	created.offset = ofVec4f(cx, cy, diam, rotate);

	const float sinRad60 = sin(ofDegToRad(60));
	//const ofColor topColor = ofColor(63, 255, 0, 13);
	//const ofColor leftColor = ofColor(193, 63, 63, 13);
	//const ofColor rightColor = ofColor(63, 63, 127, 13);

	created.d2 = diam / 2;
	float w2 = diam + created.d2;
	created.r2 = w2 / 2;
	float h = sinRad60 * diam;
	created.h3 = h / 3;
	created.h3h = created.h3 - h;


	//ofPushMatrix();
	//ofTranslate(cx*factor, cy*factor);
	//ofRotate(rotate);
	//drawCircle(-d2, h3, r2, leftColor);
	//drawCircle(d2, h3, r2, rightColor);
	//drawCircle(0, h3 - h, r2, topColor);


	if (diam > 5)
	{
		float rf = (rotate + r) / 2;
		float xx = (cx*(1 - factor) + cx*xo* (factor)) * 1;
		float yy = (cy*(1 - factor) + cy*yo* (factor)) * 1;
		created.children.push_back(createTri(xx - created.d2, yy + created.h3, created.d2, rf));
		created.children.push_back(createTri(xx, yy + created.h3 - h, created.d2, rf));
		created.children.push_back(createTri(xx + created.d2, yy + created.h3, created.d2, rf));
	}
	//ofPopMatrix();

	return created;
}

void tri::draw()
{

	const ofColor topColor = ofColor(63, 255, 0, 13);
	const ofColor leftColor = ofColor(193, 63, 63, 13);
	const ofColor rightColor = ofColor(63, 63, 127, 13);

	
	ofPushMatrix();
	ofTranslate(offset.x*factor, offset.y*factor);
	ofRotate(offset.w);
	drawCircle(-d2, h3, r2, leftColor);
	drawCircle(d2, h3, r2, rightColor);
	drawCircle(0, h3h, r2, topColor);

	for (int i = 0; i < children.size(); i++)
	{
		tri child = children[i];
		child.draw();
	}
	ofPopMatrix();
}


void tri::drawCircle(float cx, float cy, float r, ofColor color)
{
	int circleSegLen = 2;
	const int seg = 2 * PI * r / circleSegLen;
	ofSetCircleResolution(seg);

	ofSetColor(color);
	ofCircle(cx, cy, r);
}


int count(int depth, int k) {
	return 1 + k * (pow(k, depth) / (k - 1));
}

vector<tri> trilist(float diam) {
	vector<tri> list = vector<tri>();



	return list;
}


