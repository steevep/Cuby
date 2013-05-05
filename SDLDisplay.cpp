#include "SDLDisplay.hpp"

SDLDisplay::SDLDisplay(const std::string & title, Settings * settings)
{
	// Temporary variables
	int	flags;
	int	inits;

	// Init temporary variables
	flags = SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF;
	inits = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;

	// Init Attributes
	this->setFullscreen(settings->getFullscreen());
	this->setHeight(settings->getHeight());
	this->setWidth(settings->getWidth());

	// Init SDL
	if (SDL_Init(inits) == -1)
	  throw Exception(SDL_GetError());


  /*if (TTF_Init() == -1)
    throw Exception("TTF Init failed. :(");
  if (!(this->font = TTF_OpenFont("./media/font.ttf", 40)))
    exit_msg(1, "Cannot open the requested font. :(");*/

	/*
  this->hardware = (SDL_VideoInfo *)SDL_GetVideoInfo();
  this->monitor_height = this->hardware->current_h;
  this->monitor_width = this->hardware->current_w;*/

  //SDL_WM_SetIcon(SDL_LoadBMP("./media/icon.bmp"), NULL);
  this->screen = SDL_SetVideoMode(this->getWidth(), this->getHeight(), 32, flags);
  SDL_WM_SetCaption(title.c_str(), NULL);
  //SDL_ShowCursor(SDL_DISABLE);
}

SDLDisplay::~SDLDisplay()
{
  SDL_FreeSurface(this->screen);
  /*TTF_CloseFont(this->font);
  TTF_Quit();*/
  SDL_Quit();
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

// Getters
bool			SDLDisplay::getFullscreen(void) const
{
	return (this->fullscreen);
}

unsigned int	SDLDisplay::getHeight(void) const
{
	return (this->height);
}

unsigned int	SDLDisplay::getWidth(void) const
{
	return (this->width);
}


// Setters
void			SDLDisplay::setFullscreen(bool value)
{
	this->fullscreen = value;
}

void			SDLDisplay::setHeight(unsigned int value)
{
	this->height = value;
}

void			SDLDisplay::setWidth(unsigned int value)
{
	this->width = value;
}