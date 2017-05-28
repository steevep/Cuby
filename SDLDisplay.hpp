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
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include "Settings.hpp"
# include "Exception.hpp"

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
	void		EnableTransparentWindow(void);

	// Getters
	bool			getFullscreen(void) const;
	unsigned int	getHeight(void) const;
	unsigned int	getWidth(void) const;
	TTF_Font			*getFont();
	SDL_Surface		*getScreen(void);
	SDL_Event		&getEvent(void);

	// Setters
	void			setFullscreen(bool);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	height;
	unsigned int	width;
	TTF_Font		*font;
	SDL_VideoInfo	*hardware;
	SDL_Surface		*screen;
	SDL_Event		event;
};

#endif
