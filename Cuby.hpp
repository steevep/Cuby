#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

// Defines
#define PROJECT_NAME	"[Cuby]"

// Includes
#include <iostream>
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

	// Attributes
private:
	bool			quit;	
	ADisplay		*display;
	Settings		*settings;

};

