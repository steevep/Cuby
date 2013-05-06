#pragma once

// Defines
#define PROJECT_NAME	"[Cuby]"

// Includes
#include <iostream>
#include "Block.hpp"
#include "Colors.hpp"
#include "ASection.hpp"
#include "Settings.hpp"
#include "Exception.hpp"
#include "SDLDisplay.hpp"
#include "Ressources.hpp"
#include "ScreenSaver.hpp"

class		Cuby
{
	// Constructor and destructor
public:
	Cuby(void);
	~Cuby(void);

	// Members functions
public:
	void		Run(void);
	void		DrawSection(void);
	void		UpdateSection(void);
	void		HandleEvents(void);

	// Attributes
private:
	bool					quit;
	eSection				current;
	SDLDisplay				*display;
	Settings				*settings;
	Ressources				*ressources;
	std::list<ASection *>	sections;
};
