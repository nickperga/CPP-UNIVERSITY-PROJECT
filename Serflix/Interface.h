#pragma once
#include "sgg/graphics.h"
#include "defines.h"
#include <list>
#include "Widget.h"
#include "Slider.h"
#include "Movie.h"
#include "TextSegment.h"
#include "Arrow.h"


class Interface
{
	static Interface* m_instance;
	std::list<Slider*> sliders; //Sliders list
	std::list<Movie*> movies; //Movies list
	std::list<TextSegment*> texts; //Text segments list
	std::list<Arrow*> arrows; //Arrows list
	

	enum State { STATE_INIT, EVERYTHING_ELSE};
	State state;

	std::string MovieType;
	bool MovieTypesSort = false;
	Movie* Current_Movie = nullptr;

	TextSegment* m_active = nullptr;
	bool Getinloop;

	int from, to;

	Arrow* m_active_arrow = nullptr;

	inline Interface() { state = STATE_INIT; }

	
public:

	static Interface* get_Instance() { if (!m_instance) { m_instance = new Interface(); } return m_instance; }

	void init();
	void draw();
	void update();

	void MoviesListUpdate(Arrow* arrow);
};

