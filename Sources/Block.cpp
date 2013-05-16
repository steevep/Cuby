#include "Block.hpp"

extern SDL_Surface *MainScreen;

int vr = 20;

Block::Block(unsigned int blocksize, unsigned int x, unsigned int y)
{
	this->image = SDL_CreateRGBSurface(SDL_HWSURFACE, blocksize, blocksize, 32, 0, 0, 0, 0);
	this->position.x = x * blocksize;
	this->position.y = y * blocksize;
	this->position.w = blocksize;
	this->position.h = blocksize;
	this->hidden = true;
}

Block::~Block()
{
	SDL_FreeSurface(this->image);
}

void	Block::Update(void)
{  
	auto x = 0, y = 0;

	SDL_GetMouseState(&x, &y);
	if ((x >= this->position.x && x <= (this->position.x + this->position.w)) &&
		(y >= this->position.y && y <= (this->position.y + this->position.w)))
		SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, vr++, 10, 50));
	vr++;
	if (this->hidden == true)
		SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, 0,  vr, vr));
}

// Getters
bool			Block::GetHidden(void) const
{
	return (this->hidden);
}

// Setters
void			Block::SetHidden(bool value)
{
	this->hidden = value;
}

void		Block::Draw(void)
{
	if (!this->hidden)
		SDL_BlitSurface(this->image, NULL, MainScreen, &this->position);
}
