#include "FPS.hpp"
#include <sstream>

extern Ressources  *ressources;

FPS::FPS(bool hidden_value)
{
	this->img = 0;
	this->last = 0;
	this->image = NULL;

	this->position.x = 0;
	this->position.y = 0;
	this->position.w = 1;
	this->position.h = 1;
	this->hidden = hidden_value;
}

FPS::~FPS(void)
{
	if (this->image != NULL)
		SDL_FreeSurface(this->image);
}

void		FPS::Update(void)
{  
	std::ostringstream	txt;
	SDL_Color			color;
	SDL_Event			event;
	Uint8				*keys;
	int					cur;

	color.r = 255;
	color.g = 0;
	color.b = 255;

	cur = SDL_GetTicks();
	keys = SDL_GetKeyState(NULL);
	event = ressources->display->getEvent();

	// Key events
	if (event.type == SDL_KEYDOWN)
	if (keys[SDLK_F1])
		this->SetHidden(!this->GetHidden());

	// Calcute image rate
	if (cur - this->last > 1000)
	{
		if (this->image != NULL)
		{
			SDL_FreeSurface(this->image);
			this->image = NULL;
		}
		txt << img;
		this->image = TTF_RenderText_Blended(ressources->display->getFont(), txt.str().c_str(), color);
		this->last = cur;
		this->img = 0;
	}
	this->img++;
}

void		FPS::Draw(void)
{
  if (this->image != NULL && !this->hidden)
      SDL_BlitSurface(this->image, NULL, ressources->display->getScreen(), &this->position);
}
