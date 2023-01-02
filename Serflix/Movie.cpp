#include "Movie.h"
#include "sgg/graphics.h"

using namespace graphics;

Movie::Movie(const string& Name, const string& Type, const string& Directors, const string& actor, int Date)
{
	 name = Name; 
	 typeOfmovie = Type; 
	 director = Directors; 
	 MainActor = actor;
	 DateofProduction = Date; 
}

void Movie::draw()
{
	Brush br;

	//Drawing the movies image
	br.fill_opacity = 1.f;
	br.outline_opacity = 0.f;
	br.texture = path;
	drawRect(CANVAS_WIDTH / 2, 0.9f * CANVAS_HEIGHT / 2, CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2, br);

	//Drawing the texts with the movie's attributes
	br.texture = " ";
	setFont("Arial.ttf");
	drawText(0.1 * CANVAS_WIDTH / 3, 1.4 * CANVAS_HEIGHT / 2, TEXT_SIZE, "Name: " + name, br);
	drawText(0.1 * CANVAS_WIDTH / 3, 1.55 * CANVAS_HEIGHT / 2, TEXT_SIZE, "Type of movie: " + typeOfmovie, br);
	drawText(0.1 * CANVAS_WIDTH / 3, 1.7 * CANVAS_HEIGHT / 2, TEXT_SIZE, "Director: " + director, br);
	drawText(0.1 * CANVAS_WIDTH / 3, 1.85 * CANVAS_HEIGHT / 2, TEXT_SIZE, "Main Actor: " + MainActor, br);
	drawText(0.7 * CANVAS_WIDTH / 2, 1.7 * CANVAS_HEIGHT / 2, 2 * TEXT_SIZE, "Date of production: " + std::to_string(DateofProduction), br);
}

void Movie::update()
{
	
}