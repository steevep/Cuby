#ifndef		RESSOURCES_HPP
# define	RESSOURCES_HPP

// Includes
#include "Colors.hpp"
#include "Settings.hpp"
#include "SDLDisplay.hpp"

class		Ressources
{
	// Constructor and destructor
public:
	Ressources(SDLDisplay *, Settings *);
	~Ressources(void);

	// Attributes
public:
	Colors				*colors;
	SDLDisplay			*display;
	Settings			*settings;
	// Surfaces			*surfaces;
};

#endif