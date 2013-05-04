#ifndef		SDLDisplay_HPP
# define	SDLDisplay_HPP

// Includes
#include "IDisplay.hpp"

class		SDLDisplay : public IDisplay
{
	// Constructor and destructor
public:
	SDLDisplay(bool _fullscreen);
	virtual ~SDLDisplay(void);

	// Members functions
public:

	// Attributes
private:
	bool		fullscreen;
};

#endif
