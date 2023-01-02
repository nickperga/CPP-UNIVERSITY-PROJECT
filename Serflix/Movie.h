#pragma once
#include <string>
#include "Widget.h"
#include "defines.h"

class Movie: public Widget
{
	std::string name, typeOfmovie, director, path, MainActor; //Movie's attributes
	int DateofProduction;
	bool active;
	

public:
	Movie(const std::string& Name, const std::string& Type, const std::string& Directors, const std::string& actor, int Date);

	void draw();
	void update();

	inline void SetASSETPATH(std::string Path) { path = Path; }

	inline void setActive(bool Active) { active = Active; }
	inline bool getActivity() { return active; }

	inline std::string getType() { return typeOfmovie; }
	inline int getDateofProduction() { return DateofProduction; }
};