#include "Block.hpp"

extern SDL_Surface *MainScreen;

Block::Block()
{
	this->image = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOCK_SIZE, BLOCK_SIZE, 32, 0, 0, 0, 0);
  
  this->position.x = 0;
  this->position.y = 0;
  this->position.w = BLOCK_SIZE;
  this->position.h = BLOCK_SIZE;
}

Block::Block(unsigned int blocksize, unsigned int x, unsigned int y)
{
  this->image = SDL_CreateRGBSurface(SDL_HWSURFACE, blocksize, blocksize, 32, 0, 0, 0, 0);
  this->position.x = x * blocksize;
  this->position.y = y * blocksize;
  this->position.w = blocksize;
  this->position.h = blocksize;
}

Block::~Block()
{
  SDL_FreeSurface(this->image);
}

void	Block::Update(void)
{  
	SDL_FillRect(this->image, NULL, SDL_MapRGB(this->image->format, 255, 0, 0));
}

void		Block::Draw(void)
{
  SDL_BlitSurface(this->image, NULL, MainScreen, &this->position);
}
