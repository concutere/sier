#pragma once

#include "ofMain.h";

class tri
{
public:
	tri();
	~tri();

	static float factor, spin, xo, yo, rr, r;

	int depth; //0based

	static tri construct(float diam);
	static tri reconstruct();

	ofVec4f offset;
	float x, y, rotate, diam;

	void draw();

	static vector<tri> trilist(float diam);

protected:
	static float maxDiam;
	float r2,d2, h3, h3h;

	vector<tri> children;
	static void drawCircle(float cx, float cy, float r, ofColor color);

	static tri createTri(float cx, float cy, float diam, float rotate);
};

