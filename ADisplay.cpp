#include "ADisplay.hpp"

// Getters
bool			ADisplay::getFullscreen(void)
{
	return (this->fullscreen);
}

unsigned int	ADisplay::getHeight(void)
{
	return (this->height);
}

unsigned int	ADisplay::getWidth(void)
{
	return (this->width);
}


// Setters
void			ADisplay::setFullscreen(bool value)
{
	this->fullscreen = value;
}

void			ADisplay::setHeight(unsigned int value)
{
	this->height = value;
}

void			ADisplay::setWidth(unsigned int value)
{
	this->width = value;
}