#ifndef		SDLDisplay_HPP
# define	SDLDisplay_HPP

// Includes
#include "SDL.h"
#include "ADisplay.hpp"
#include "Exception.hpp"

class		SDLDisplay : public ADisplay
{
	// Constructor and destructor
public:
	SDLDisplay(bool);
	virtual ~SDLDisplay(void);

	// Members functions
public:
	virtual void init(void);
	virtual void refresh(void);
	virtual eKey pressedKey(void);

	// Attributes
private:
	SDL_Surface	*screen;
};

#endif
