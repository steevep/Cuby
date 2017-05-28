#include "ScreenSaver.hpp"

ScreenSaver::ScreenSaver(Ressources *_ressources)
{
	this->section = SCREENSAVER;
	this->ressources = _ressources;
	this->CreateBlocks();
}

ScreenSaver::~ScreenSaver(void)
{

}

void ScreenSaver::Draw(void)
{

}

void ScreenSaver::Update(void)
{
	AObject				*item;

	unsigned int vertical_blocks = this->ressources->display->getHeight() / this->ressources->settings->getBlocksize();
	unsigned int horizontal_blocks = this->ressources->display->getWidth() / this->ressources->settings->getBlocksize();

	unsigned int x = ressources->RandU(0, horizontal_blocks);
	unsigned int y = ressources->RandU(0, vertical_blocks);

	// if (x < horizontal_blocks && y <= vertical_blocks)
	// {
		item = this->GetObject(x/* * this->ressources->settings->getBlocksize()*/, y /* * this->ressources->settings->getBlocksize() */);

		if (item != NULL)
		{
			SDL_Surface * item_surface = reinterpret_cast<Block *>(item)->getSurface();

			int r = ressources->RandU(0, 255);
			int g = ressources->RandU(0, 255);
			int b = ressources->RandU(0, 255);

			SDL_FillRect(item_surface, NULL, SDL_MapRGB(item_surface->format, r, g, b));
			//reinterpret_cast<Block *>(item)->setHidden(false);
		}
		// x++;
	// }
	// if (x == horizontal_blocks && y < vertical_blocks)
	// {
	// 	y++;
	// 	x = 0;
	// }

	// this->ressources->offset_width++;
}

void ScreenSaver::CreateBlocks(void)
{
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int vertical_blocks = ressources->blocks_h_count;
	unsigned int horizontal_blocks = ressources->blocks_w_count;

	while (y <= vertical_blocks)
	{
		x = 0;
		while (x < horizontal_blocks)
		{
			Block *new_block = new Block(this->ressources->settings->getBlocksize(), x, y, false);
			this->AddObject(new_block);
			x++;
		}
		y++;
	}
}
