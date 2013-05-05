#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

// Defines
#define PROJECT_NAME	"[Cuby]"

// Includes
#include <iostream>
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
	void Run(void);
	void DrawSection(void);
	void UpdateSection(void);
	void HandleEvents(void);

	// Attributes
private:
	bool					quit;
	SDLDisplay				*display;
	Settings				*settings;
	std::list<Section *>	sections;
};

