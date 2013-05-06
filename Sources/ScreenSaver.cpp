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
void ScreenSaver::CreateBlocks(void)
{
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int vertical_blocks;
	unsigned int horizontal_blocks;

	vertical_blocks = this->ressources->display->getHeight() / this->ressources->settings->getBlocksize();
	horizontal_blocks = this->ressources->display->getWidth() / this->ressources->settings->getBlocksize();
	while (y <= vertical_blocks)
	{
		x = 0;
		while (x < horizontal_blocks)
		{
			this->AddObject(new Block(this->ressources->settings->getBlocksize(), x, y));
			x++;
		}
		y++;
	}
}