#pragma once
#include "Widget.h"
#include "sgg/graphics.h"
#include "defines.h"

class Arrow: public Widget
{
	float m_pos[2]; //Holds the position of the arrow
	std::string path; //Gives the arrows image to brush
	bool highligted = false; 

public:
	inline Arrow(float x, float y) { m_pos[0] = x; m_pos[1] = y; }
	void draw();
	void update();

	bool contains(float x, float y);
	inline void setHighlighted(bool x) { highligted = x; }

	inline void setAssetPath(std::string Path) { path = Path; }
	inline std::string GetPath() { return path; }
};