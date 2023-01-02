#include "Slider.h"

using namespace graphics;
using namespace std;

void Slider::draw()
{
	Brush brs;

	//Drawing Slider's rectangle
	brs.outline_opacity = 1.f;
	brs.fill_opacity = 1.f;
	brs.outline_width = 0.5f;
	SetColor(brs.fill_color, 0.2f, 0.2f, 0.2f);
	drawRect(m_pos2[0], m_pos2[1], CANVAS_WIDTH / 4, CANVAS_HEIGHT / 60, brs);

	//Drawing Slider
	SetColor(brs.fill_color, 1.f, 1.f, 1.f);
	SetColor(brs.outline_color, 0.f, 0.f, 0.f);
	brs.outline_opacity = 1.f;
	drawRect(m_pos1[0], m_pos1[1], CANVAS_WIDTH / 78, CANVAS_HEIGHT / 20, brs);

	//Drawing the texts around the slider
	SetColor(brs.fill_color, 0.f, 0.f, 0.f);
	setFont("Arial.ttf");
	drawText(m_pos2[0] - CANVAS_WIDTH / 7, m_pos2[1] + CANVAS_HEIGHT / 20, TEXT_SIZE, "2000", brs);
	drawText(m_pos2[0] + CANVAS_WIDTH / 9, m_pos2[1] + CANVAS_HEIGHT / 20, TEXT_SIZE, "2022", brs);
	drawText(m_pos2[0] - CANVAS_WIDTH / 20, m_pos2[1] - CANVAS_HEIGHT / 15, 1.5 * TEXT_SIZE, upper_text, brs);
	drawText(m_pos1[0] - CANVAS_WIDTH / 60, m_pos1[1] - CANVAS_HEIGHT / 30, TEXT_SIZE, to_string(cur_date), brs);
}

void Slider::update()
{
	MouseState ms;
	getMouseState(ms);

	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);


	if (ms.button_left_pressed && contains(mx, my))
	{
		setActive(true);
	}

	mx = MouseXcheck(mx);
	my = MouseYcheck(my);

	if (ms.dragging && m_active)
	{
		setRectposX(mx);
		setRectposY(my);
		setDate(mx);
	}

	if (ms.button_left_released && m_active)
	{
		setActive(false);
	}

}

//Normalizes the mouse x with the slider's position
float Slider::MouseXcheck(float x)
{
	if (x <= m_pos2[0] - CANVAS_WIDTH / 8)
	{
		x = m_pos2[0] - CANVAS_WIDTH / 8;
	}
	else if (x >= m_pos2[0] + CANVAS_WIDTH / 8)
	{
		x = m_pos2[0] + CANVAS_WIDTH / 8;
	}
	return x;
}

//Normalizes the mouse y with the slider's position
float Slider::MouseYcheck(float y)
{
	if (y != CANVAS_HEIGHT / 10)
	{
		y = CANVAS_HEIGHT / 10;
	}
	return y;
}

bool Slider::contains(float x1, float y1)
{
	return distance(x1, y1, m_pos1[0], m_pos1[1]) < S_RECTSIZE;
}

//Changes the date which the slider represents
void Slider::setDate(float x)
{
	for (int i = 0; i < 23; i++)
	{
		if (x <= (m_pos2[0] - CANVAS_WIDTH / 8 + (i * CANVAS_WIDTH / 88)))
		{
			cur_date = 2000 + i;
			break;
		}
	}
}
