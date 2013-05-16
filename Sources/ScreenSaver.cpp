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
	/*AObject				*item;
	static unsigned int x = 0;
	static unsigned int y = 0;
	unsigned int vertical_blocks = this->ressources->display->getHeight() / this->ressources->settings->getBlocksize();
	unsigned int horizontal_blocks = this->ressources->display->getWidth() / this->ressources->settings->getBlocksize();

	if (x < horizontal_blocks && y <= vertical_blocks)
	{
		item = this->GetObject(x * this->ressources->settings->getBlocksize(), y * this->ressources->settings->getBlocksize());
		if (item != NULL)
		{
			reinterpret_cast<Block *>(item)->SetHidden(false);
		}
		x++;
	}
	if (x == horizontal_blocks && y < vertical_blocks)
	{
		y++;
		x = 0;
	}*/
}

void ScreenSaver::CreateBlocks(void)
{
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int vertical_blocks = this->ressources->display->getHeight() / this->ressources->settings->getBlocksize();
	unsigned int horizontal_blocks = this->ressources->display->getWidth() / this->ressources->settings->getBlocksize();

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