#pragma once

#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 16.0f

#define ASSET_PATH ".\\assets\\"

#define S_RECTSIZE 0.2f
#define TEXT_SIZE 0.4f
#define TEXT_COLOR 0.4f
#define TRIANGLE_SIZE 0.7f;

#define SetColor(c, r, g, b) {c[0] = r; c[1] = g; c[2] = b;}

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}