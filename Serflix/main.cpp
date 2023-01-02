#include "sgg/graphics.h"
#include "defines.h"
#include <string>
#include "Movie.h"
#include "Interface.h" 
#include <iostream>

using namespace graphics;

void draw()
{
	Interface* interface = Interface::get_Instance();
	interface->draw();

}

void update(float m)
{
	Interface* interface = Interface::get_Instance();
	interface->update();
}

int main(int argc, char** argv)
{
	createWindow(1024, 720, "Serflex");

	Interface* interface = Interface::get_Instance();

	setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	setCanvasScaleMode(CANVAS_SCALE_FIT);

	setUpdateFunction(update);
	setDrawFunction(draw);
	
	startMessageLoop();

	return 0;
}