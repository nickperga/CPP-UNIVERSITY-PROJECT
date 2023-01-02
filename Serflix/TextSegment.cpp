#include "TextSegment.h"

using namespace graphics;

void TextSegment::draw()
{
	Brush br;

	//Drawing the text segment depending if it is highlighted or not
	br.fill_opacity = 0.7f;
	if (m_highlighted)
	{
		br.outline_opacity = 1.f;
		SetColor(br.fill_color, 0.12f, 0.12f, 0.12f);
	}
	else 
	{
		br.outline_opacity = 0.f;
		SetColor(br.fill_color, TEXT_COLOR, TEXT_COLOR, TEXT_COLOR);
	}
	drawRect(m_pos[0], m_pos[1], CANVAS_WIDTH / 10, CANVAS_HEIGHT / 23, br);

	//Draws the inside text
	SetColor(br.fill_color, 1.f, 1.f, 1.f);
	setFont("Arial.ttf");
	drawText(m_pos[2], m_pos[3], TEXT_SIZE * 1.5f, text, br);
}

void TextSegment::update()
{

}

//Finds the borders of each rectangle and checks if the mouse is inside them
bool TextSegment::contains(float x, float y)
{
	if ((x <= m_pos[0] - (CANVAS_WIDTH / 20) || x >= m_pos[0] + (CANVAS_WIDTH / 20)) || (y <= m_pos[1] - (CANVAS_HEIGHT / 46) || y >= m_pos[1] + (CANVAS_HEIGHT / 46)))
	{
		return false;
	}
	return true;
}