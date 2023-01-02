#include "Interface.h"
#include <iostream>

using namespace graphics;
using namespace std;

void Interface::init()
{
	//Sliders initialization
	Slider* slider1 = new Slider(0.9 * CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10, 0.65 * CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10);
	slider1->setUpperText("From:");
	slider1->setCurDate(2000);
	from = slider1->getTime();
	sliders.push_back(slider1);

	Slider* slider2 = new Slider(2.5 * CANVAS_WIDTH / 3, CANVAS_HEIGHT / 10, 1.916 * CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10);
	slider2->setUpperText("To:");
	slider2->setCurDate(2022);
	to = slider2->getTime();
	sliders.push_back(slider2);

	//Movies initialization
	Movie* movie1 = new Movie("AVATAR", "Action", "James Cameron", "Sam Worthington", 2009);
	movie1->SetASSETPATH(ASSET_PATH + string("Avatar.png"));
	movies.push_back(movie1);

	Movie* movie2 = new Movie("Skyfall", "Action", "Sam Mendes", "Daniel Craig", 2012);
	movie2->SetASSETPATH(ASSET_PATH + string("Skyfall.png"));
	movies.push_back(movie2);
	
	Movie* movie3 = new Movie("Interstellar", "Adventure", "Christopher Nolan", "Matthew McConaughey", 2014);
	movie3->SetASSETPATH(ASSET_PATH + string("Interstellar.png"));
	movies.push_back(movie3);

	Movie* movie4 = new Movie("Whiplash", "Drama", "Damien Chazelle", "Milles Teller", 2014);
	movie4->SetASSETPATH(ASSET_PATH + string("Whiplash.png"));
	movies.push_back(movie4);

	Movie* movie5 = new Movie("Guardians of the Galaxy", "Action", "James Gunn", "Chris Patt", 2014);
	movie5->SetASSETPATH(ASSET_PATH + string("Guardians of the Galaxy.png"));
	movies.push_back(movie5);

	Movie* movie6 = new Movie("Django: Unchained", "Drama", "Quentin Tarantino", "Jamie Foxx", 2012);
	movie6->SetASSETPATH(ASSET_PATH + string("Django Unchained.png"));
	movies.push_back(movie6);

	Movie* movie7 = new Movie("Iron Man 3", "Action", "Shane Block", "Robert Downey Jr", 2013);
	movie7->SetASSETPATH(ASSET_PATH + string("Iron man 3.png"));
	movies.push_back(movie7);
	
	Movie* movie8 = new Movie("The Dark Knight Rises", "Action", "Christopher Nolan", "Christian Bale", 2012);
	movie8->SetASSETPATH(ASSET_PATH + string("batmanthe_dark_knight_rises_2012.png"));
	movies.push_back(movie8);

	Movie* movie9 = new Movie("Joker", "Crime", "Todd Phillips", "Joaquin Phoenix", 2019);
	movie9->SetASSETPATH(ASSET_PATH + string("Joker.png"));
	movies.push_back(movie9);

	//Text Segments initialization
	TextSegment* text1 = new TextSegment("Action", 0.11 * CANVAS_WIDTH / 2, 0.45 * CANVAS_HEIGHT / 10, 0.05 * CANVAS_WIDTH / 2, 0.55 * CANVAS_HEIGHT / 10);
	texts.push_back(text1);

	TextSegment* text2 = new TextSegment("Drama", 0.11 * CANVAS_WIDTH / 2, 0.95 * CANVAS_HEIGHT / 10, 0.05 * CANVAS_WIDTH / 2, 1.05 * CANVAS_HEIGHT / 10);
	texts.push_back(text2);

	TextSegment* text3 = new TextSegment("Crime", 0.31 * CANVAS_WIDTH / 2, 0.45 * CANVAS_HEIGHT / 10, 0.25 * CANVAS_WIDTH / 2, 0.55 * CANVAS_HEIGHT / 10);
	texts.push_back(text3);

	TextSegment* text4 = new TextSegment("Adventure", 0.31 * CANVAS_WIDTH / 2, 0.95 * CANVAS_HEIGHT / 10, 0.215 * CANVAS_WIDTH / 2, 1.05 * CANVAS_HEIGHT / 10);
	texts.push_back(text4);

	//Arrows initialization
	Arrow* arrow1 = new Arrow(1.2 * CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2);
	arrow1->setAssetPath(ASSET_PATH + string("arrowl.png"));
	arrows.push_back(arrow1);

	Arrow* arrow2 = new Arrow(2.8 * CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2);
	arrow2->setAssetPath(ASSET_PATH + string("arrowr.png"));
	arrows.push_back(arrow2);
}

void Interface::draw()
{
	Brush br;

	//Canvas filling
	br.fill_opacity = 1.f;
	br.outline_opacity = 0.f;
	br.texture = ASSET_PATH + std::string("10-109776_transparent-black-background-png-semi-transparent-background-png.png");
	drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	br.texture = "";
	SetColor(br.fill_color, 0.f, 0.0f, 1.f);
	drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 12, CANVAS_WIDTH, CANVAS_HEIGHT / 6, br);

	//Sliders drawing
	for (auto slider : sliders)
	{
		slider->draw();
	}

	//Current movie and arrows drawing
	if (Current_Movie)
	{
		for (auto movie : movies)
		{
			if (movie == Current_Movie)
			{
				movie->draw();
				break;
			}
		}

		for (auto arrow : arrows)
		{
			arrow->draw();
		}
	}

	//Text Segments drawing
	for (auto text : texts)
	{
		text->draw();
	}
}

//Interface's m_instance initialization
Interface* Interface::m_instance = nullptr;

void Interface::update()
{
	//Initialization of all the lists and Current movie's variable
	if (state == STATE_INIT)
	{
		init();
		preloadBitmaps(ASSET_PATH);
		Current_Movie = movies.front();
		state = EVERYTHING_ELSE;
	}

	MouseState ms;
	getMouseState(ms);

	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	
	if (state == EVERYTHING_ELSE)
	{
		//Movies update function
		for (auto movie : movies)
		{
			movie->update();
		}

		//Sliders update function and checking each slider change to change current movie
		for (auto slider : sliders)
		{
			int from1 = sliders.front()->getTime();
			int to1 = sliders.back()->getTime();
			slider->update();
			if (slider == sliders.front())
			{
				from = slider->getTime();
			}
			else
			{
				to = slider->getTime();
			}
			if (from1 != from || to1 != to)
			{
				bool found = false;
				for (auto movie : movies)
				{
					if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && MovieType == "")
					{
						Current_Movie = movie;
						found = true;
						break;
					}
					else if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && MovieType == movie->getType())
					{
						Current_Movie = movie;
						found = true;
						break;
					}
				}
				if (!found)
				{
					Current_Movie = nullptr;
				}
			}
		}

		//Arrows update function and holding active arrow
		for (auto arrow : arrows)
		{
			arrow->update();
			if (ms.button_left_pressed && arrow->contains(mx, my))
			{
				m_active_arrow = arrow;
				break;
			}
			else
			{
				m_active_arrow = nullptr;
			}
		}

		//Current movie update function with arrows
		if (m_active_arrow)
		{
			MoviesListUpdate(m_active_arrow);
		}
		
		//Lowlights the active text segment
		Getinloop = true;
		if (m_active)
		{
			if (ms.button_left_pressed && m_active->contains(mx, my))
			{
				m_active->setActive(false);
				m_active->setHighlighted(false);
				m_active = nullptr;
				Getinloop = false;
				MovieTypesSort = false;
				MovieType = "";
			}
		}

		//Highlights the clicked text segment
		if (Getinloop) {
			for (auto text : texts)
			{
				if (ms.button_left_pressed && text->contains(mx, my) && (!text->getActivity()))
				{
					MovieTypesSort = true;
					if (m_active == nullptr)
					{
						MovieType = text->getText();
						text->setActive(true);
						text->setHighlighted(true);
						m_active = text;
						for (auto movie : movies)
						{
							if (movie->getType() == MovieType)
							{
								Current_Movie = movie;
								break;
							}
						}
					}
					else
					{
						m_active->setActive(false);
						m_active->setHighlighted(false);
						m_active = text;
						m_active->setActive(true);
						m_active->setHighlighted(true);
						MovieType = text->getText();
						//Changes the current movie variable with the first movie from list which is the type selected
						for (auto movie : movies)
						{
							if (movie->getType() == MovieType)
							{
								Current_Movie = movie;
								break;
							}
						}
					}
					break;
				}
			}
		}
	}
}

void Interface::MoviesListUpdate(Arrow* arrow)
{
	bool CurMovieFound = false;
	bool changed = false;
	Movie* m = Current_Movie;
	//Changes the movies without a certain filter
	if (from == 2000 && to == 2022 && MovieType == "")
	{
		if (arrow->GetPath() == ASSET_PATH + string("arrowr.png"))
		{
			//When arrow is the right checks if the current movie is the last of the list and goes at the beginning
			if (Current_Movie == movies.back())
			{
				Current_Movie = movies.front();
			}//Else it checks the list for the next movie
			else
			{
				for (auto movie : movies)
				{
					if (CurMovieFound)
					{
						Current_Movie = movie;
						break;
					}
					if (movie == Current_Movie)
					{
						 CurMovieFound = true;
					}
				}
			}
		}
		else if (arrow->GetPath() == ASSET_PATH + string("arrowl.png"))
		{
			//If the arrow is the left checks if the current movie is the first and goes to the end of the list
			if (Current_Movie == movies.front())
			{
				Current_Movie = movies.back();
			}//Else it checks the list for the previous movie of the current 
			else
			{
				for (auto movie : movies)
				{
					if (m == movie) { break; }
					if (!CurMovieFound)
					{
						Current_Movie = movie;
					}
				}
			}
		}
	}/*The same logic is applied to the next lines where filters are used for the movies like date of production and
	 Movie type. If the arrow is right then it checks the part of the list after the current movie and if a movie 
	 cannot be found checks the part of the list before the movie. If the arrow is left it checks firstly the part 
	 of the list before the movie and if it a movie cannot be found checks the part of the list after the movie. In
	 each occassion the active filters are applied.*/
	else if ((from != 2000 || to != 2022) && MovieType == "")
	{	
		if (arrow->GetPath() == ASSET_PATH + string("arrowr.png"))
		{
			for (auto movie : movies)
			{
				if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && CurMovieFound)
				{
					Current_Movie = movie;
					changed = true;
					break;
				}
				if (Current_Movie == movie) { CurMovieFound = true; }
			}
			if (!changed)
			{
				for (auto movie : movies)
				{
					if (m == movie) { break; }
					if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to)
					{
						Current_Movie = movie;
						break;
					}
				}
			}
		}
		else if (arrow->GetPath() == ASSET_PATH + string("arrowl.png"))
		{
			for (auto movie : movies)
			{
				if (m == movie) { break; }
				if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to)
				{
					Current_Movie = movie;
					changed = true;
				}
			}
			if (!changed)
			{
				for (auto movie : movies)
				{
					if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && CurMovieFound)
					{
						Current_Movie = movie;
					}
					if (Current_Movie == movie) { CurMovieFound = true; }
				}
			}
		}
	}
	else if (from == 2000 && to == 2022 && MovieType != "")
	{
		if (arrow->GetPath() == ASSET_PATH + string("arrowr.png"))
		{
			for (auto movie : movies)
			{
				if (movie->getType() == MovieType && CurMovieFound)
				{
					Current_Movie = movie;
					changed = true;
					break;
				}
				if (Current_Movie == movie) { CurMovieFound = true; }
			}
			if (!changed)
			{
				CurMovieFound = false;
				for (auto movie : movies)
				{
					if (m == movie) { break; }
					if (movie->getType() == MovieType && !CurMovieFound)
					{
						Current_Movie = movie;
						break;
					}
					
				}
			}
		}
		else if (arrow->GetPath() == ASSET_PATH + string("arrowl.png"))
		{
			for (auto movie : movies)
			{
				if (m == movie) { break; }
				if (movie->getType() == MovieType && !CurMovieFound)
				{
					Current_Movie = movie;
					changed = true;
				}
			}
			if (!changed)
			{
				for (auto movie : movies)
				{
					if (movie->getType() == MovieType && CurMovieFound)
					{
						Current_Movie = movie;
					}
					if (movie == m) { CurMovieFound = true; }
				}
			}
		}
	}
	else if ((from != 2000 || to != 2022) && MovieType != "")
	{
		if (arrow->GetPath() == ASSET_PATH + string("arrowr.png"))
		{
			for (auto movie : movies)
			{
				if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && movie->getType() == MovieType && CurMovieFound)
				{
					Current_Movie = movie;
					changed = true;
					break;
				}
				if (movie == m) { CurMovieFound = true; }
			}
			if (!changed)
			{
				for (auto movie : movies)
				{
					if (movie == m) { break; }
					if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && movie->getType() == MovieType)
					{
						Current_Movie = movie;
						break;
					}
				}
			}
		}
		else if (arrow->GetPath() == ASSET_PATH + string("arrowl.png"))
		{
			for (auto movie : movies)
			{

				if (movie == m) { break; }
				if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && movie->getType() == MovieType)
				{
					Current_Movie = movie;
					changed = true;
				}
			}
			if (!changed)
			{
				for (auto movie : movies)
				{
					if (m == movie) { CurMovieFound = true; }
					if (movie->getDateofProduction() >= from && movie->getDateofProduction() <= to && movie->getType() == MovieType && CurMovieFound)
					{
						Current_Movie = movie;
					}
				}
			}
		}
	}
}


