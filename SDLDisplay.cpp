#include "SDLDisplay.hpp"

SDLDisplay::SDLDisplay(bool _fullscreen)
{
	// Init Attributes
	this->setFullscreen(_fullscreen);

	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw Exception(SDL_GetError());
}

SDLDisplay::~SDLDisplay()
{
  
}

void SDLDisplay::init(void)
{
  
}

void SDLDisplay::refresh(void)
{
  
}

eKey SDLDisplay::pressedKey(void)
{
	return (ESC);
}
