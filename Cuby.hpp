#pragma once

// Defines
#define PROJECT_NAME	"[Cuby]"

// Includes
#include <iostream>
#include "Block.hpp"
#include "Section.hpp"
#include "Settings.hpp"
#include "Exception.hpp"
#include "SDLDisplay.hpp"

class Cuby
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
	void		CreateBlocks(eSection);
	Section *	GetSection(eSection);

	// Attributes
private:
	bool					quit;
	eSection				current;
	SDLDisplay				*display;
	Settings				*settings;
	std::list<Section *>	sections;
};
