#include "SDLDisplay.hpp"

SDLDisplay::SDLDisplay(const std::string & title, Settings * settings)
{
	// Temporary variables
	int	flags;
	int	inits;

	// Some test for unix
	// SDL_putenv("SDL_VIDEO_CENTERED=center");

	// Init temporary variables
	flags = SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF/* | SDL_NOFRAME*/;
	inits = SDL_INIT_VIDEO/* | SDL_INIT_AUDIO */| SDL_INIT_TIMER;

	// Init Attributes
	this->setFullscreen(settings->getFullscreen());
	this->setHeight(settings->getHeight());
	this->setWidth(settings->getWidth());

	// Init SDL
	if (SDL_Init(inits) == -1)
		throw Exception(SDL_GetError());

	this->hardware = (SDL_VideoInfo *)SDL_GetVideoInfo();

	if (TTF_Init() == -1)
		throw Exception("TTF Init failed. :(");

	if (!(this->font = TTF_OpenFont("Assets/font.ttf", 32)))
		throw Exception("Cannot open the requested font. :(");

	/* this->hardware = (SDL_VideoInfo *)SDL_GetVideoInfo();
	this->monitor_height = this->hardware->current_h;
	this->monitor_width = this->hardware->current_w;*/

	//SDL_WM_SetIcon(SDL_LoadBMP("./media/icon.bmp"), NULL);
	if (this->fullscreen)
	{
		this->screen = SDL_SetVideoMode(this->hardware->current_w, this->hardware->current_h, 32, flags);
		settings->setHeight(this->hardware->current_h);
		settings->setWidth(this->hardware->current_w);
		this->setHeight(this->hardware->current_h);
		this->setWidth(this->hardware->current_w);
	}
	else
		this->screen = SDL_SetVideoMode(this->getWidth(), this->getHeight(), 32, flags);
	if (!this->screen)
		throw Exception(SDL_GetError());
	SDL_WM_SetCaption(title.c_str(), NULL);
	// SDL_ShowCursor(SDL_DISABLE);
}

SDLDisplay::~SDLDisplay()
{
  SDL_FreeSurface(this->screen);
  TTF_CloseFont(this->font);
  TTF_Quit();
  SDL_Quit();
}

void SDLDisplay::EnableTransparentWindow(void)
{
    // SDL_SysWMinfo	info;
	// HWND			hwnd;
	//
    // SDL_VERSION(&info.version);
    // if (SDL_GetWMInfo(&info))
    //     hwnd = info.window;
    // SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    // SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 1, LWA_COLORKEY);
}

void SDLDisplay::Clear(void)
{
	SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 0, 1, 0));
}

void SDLDisplay::Refresh(void)
{
	SDL_Flip(this->screen);
	// SDL_Delay(10);
}

eEvent SDLDisplay::HandleEvents(void)
{
  SDL_PollEvent(&this->event);

  if (this->event.type == SDL_QUIT)
    return (QUIT);
  if (this->event.type == SDL_VIDEORESIZE)
    return (RESIZE);
  return (NOEVENT);
}

eKey SDLDisplay::PressedKey(void)
{
	Uint8 *keys;

	if (this->event.type == SDL_KEYDOWN)
	{
		keys = SDL_GetKeyState(NULL);
		if (keys[SDLK_ESCAPE])
			return (ESC);
	}
	return (NOKEY);
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

TTF_Font		*SDLDisplay::getFont(void)
{
	return (this->font);
}

SDL_Surface		*SDLDisplay::getScreen(void)
{
	return (this->screen);
}

SDL_Event		&SDLDisplay::getEvent(void)
{
	return (this->event);
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
