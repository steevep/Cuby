#ifndef		SDLDisplay_HPP
# define	SDLDisplay_HPP

// Defines
#define BLOCK	40

// Type definitions
typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	ESC
}	eKey;

// Includes
#include "SDL.h"
#include "Settings.hpp"
#include "Exception.hpp"

class		SDLDisplay
{
	// Constructor and destructor
public:
	SDLDisplay(const std::string &, Settings *);
	~SDLDisplay(void);

	// Members functions
public:
	void init(void);
	void refresh(void);
	eKey pressedKey(void);

		// Getters
public:
	bool			getFullscreen(void) const;
	unsigned int	getHeight(void) const;
	unsigned int	getWidth(void) const;

	// Setters
public:
	void			setFullscreen(bool);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	height;
	unsigned int	width;
	SDL_Surface		*screen;
};

#endif
