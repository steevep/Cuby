#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

// Defines
#define PROJECT_NAME	"[Cuby]"

// Includes
#include <iostream>
#include "IDisplay.hpp"
#include "Settings.hpp"
#include "Exception.hpp"

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
	IDisplay		*display;
	Settings		*settings;

};

