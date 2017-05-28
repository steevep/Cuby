#include "Block.hpp"

extern Ressources  *ressources;

int vr = 20;

Block::Block(unsigned int blocksize, unsigned int x, unsigned int y, bool hidden_value)
{
	this->image = SDL_CreateRGBSurface(SDL_HWSURFACE, blocksize, blocksize, 32, 0, 0, 0, 0);
	this->position.x = x * blocksize;
	this->position.y = y * blocksize;
	this->position.w = blocksize;
	this->position.h = blocksize;
	this->hidden = hidden_value;

	int r = ressources->RandU(0, 255);
	int g = ressources->RandU(0, 255);
	int b = ressources->RandU(0, 255);

	SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, r, g, b));
}

Block::~Block()
{
	if (this->image != NULL)
		SDL_FreeSurface(this->image);
}

void	Block::Update(void)
{
	auto x = 0, y = 0;
	auto x_true = false, y_true = false;

	SDL_GetMouseState(&x, &y);
	// x -= ressources->offset_width;
	// y -= ressources->offset_height;
	x_true = (x >= this->position.x && x <= (this->position.x + this->position.w));
	y_true = (y >= this->position.y && y <= (this->position.y + this->position.w));

	if (x_true && y_true) {
		SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, vr, 10, 50));
		vr += 3;
	}

	if (this->hidden == true)
		SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, 0,  vr, vr));
}

void		Block::Draw(void)
{
	SDL_Rect tmp;

	if (!this->hidden)
	{
		tmp.x = this->position.x + ressources->offset_width;
		tmp.y = this->position.y + ressources->offset_height;
		SDL_BlitSurface(this->image, NULL, ressources->display->getScreen(), &tmp);
	}
}
