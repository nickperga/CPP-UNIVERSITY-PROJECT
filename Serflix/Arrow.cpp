#include "Arrow.h"

using namespace graphics;

void Arrow::draw()
{
	Brush br;

	//Arrow drawing which changes if its highlighted or not
	br.texture = path;
	br.fill_opacity = 1.f;
	br.outline_opacity = 0.f;
	if (highligted)
	{
		SetColor(br.fill_color, 1.f, 1.f, 0.8);
	}
	else
	{
		SetColor(br.fill_color, 1.f, 1.f, 1.f);
	}
	drawRect(m_pos[0], m_pos[1], CANVAS_WIDTH / 15, CANVAS_HEIGHT / 8, br);
}

void Arrow::update()
{
	MouseState ms;
	getMouseState(ms);

	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	if (contains(mx, my))
	{
		setHighlighted(true);
	}
	else
	{
		setHighlighted(false);
	}


}

bool Arrow::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < TRIANGLE_SIZE;
}