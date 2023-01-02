#pragma once

class Widget
{
public:
	virtual void draw() {};
	virtual void update() {};
	virtual bool contains(float x, float y) { return true; };
};
