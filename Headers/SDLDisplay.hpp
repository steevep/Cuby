#ifndef		SDLDisplay_HPP
# define	SDLDisplay_HPP

// Type definitions
typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	ESC,
	NOKEY
}	eKey;

typedef enum
{
	QUIT,
	RESIZE,
	NOEVENT
}	eEvent;

// Includes
# include "SDL.h"
# include "Settings.hpp"
# include "Exception.hpp"

# include <windows.h>
# include "SDL_syswm.h"

class		SDLDisplay
{
	// Constructor and destructor
public:
	SDLDisplay(const std::string &, Settings *);
	~SDLDisplay(void);

	// Members functions
public:
	void		Clear(void);
	void		Refresh(void);
	eKey		PressedKey(void);
	eEvent		HandleEvents(void);
	void		EnableTransparentWindows(void);

	// Getters
	bool			getFullscreen(void) const;
	unsigned int	getHeight(void) const;
	unsigned int	getWidth(void) const;
	SDL_Surface		*getScreen(void);

	// Setters
	void			setFullscreen(bool);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	height;
	unsigned int	width;
	SDL_VideoInfo	*hardware;
	SDL_Surface		*screen;
	SDL_Event		event;
};

#endif
