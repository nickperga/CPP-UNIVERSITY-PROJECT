#pragma once
#include "sgg/graphics.h"
#include "defines.h"
#include <list>
#include "Widget.h"

class Slider : public Widget
{
	float m_pos2[2]; //Slider's rectangle position
	float m_pos1[2]; //Slider's position
	bool m_active = false;
	std::string upper_text; //Current date which slider shows
	int cur_date;

public:
	Slider(float rect1x, float rect1y, float rect2x, float rect2y) { m_pos2[0] = rect1x; m_pos2[1] = rect1y; m_pos1[0] = rect2x; m_pos1[1] = rect2y; }

	void draw();
	void update();

	inline void setActive(bool active) { m_active = active; }

	inline void setRectposX(float x) { m_pos1[0] = x; }
	inline void setRectposY(float y) { m_pos1[1] = y; }

	inline void setUpperText(std::string text) { upper_text = text; }
	inline void setCurDate(int x) { cur_date = x; }

	float MouseXcheck(float x);
	float MouseYcheck(float y);

	bool contains(float x1, float y1);

	inline int getTime() { return cur_date; }

	void setDate(float x);
};