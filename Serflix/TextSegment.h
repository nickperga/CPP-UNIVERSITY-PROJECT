#pragma once
#include <string>
#include "Widget.h"
#include "sgg/graphics.h"
#include "defines.h"

class TextSegment : public Widget
{
	std::string text;
	float m_pos[4]; //Text segmnent's position and text inside it
	bool active = false;
	bool m_highlighted = false;

public:
	inline TextSegment(std::string Text, float position1, float position2, float position3, float position4) { text = Text; m_pos[0] = position1; m_pos[1] = position2; m_pos[2] = position3; m_pos[3] = position4; }
	

	void draw();
	void update();

	bool contains(float x, float y);

	inline void setActive(bool Active) { active = Active; }
	inline bool getActivity() { return active; }
	inline void setHighlighted(bool H) { m_highlighted = H; }

	inline std::string getText() { return text; }
};