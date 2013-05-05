#include "Settings.hpp"

Settings::Settings(const std::string & configurationFile)
{
	this->height = 600;
	this->width = 1024;
	this->fullscreen = false;
}

Settings::~Settings()
{
  
}

// Getters
bool			Settings::getFullscreen(void) const
{
	return (this->fullscreen);
}

unsigned int	Settings::getHeight(void) const
{
	return (this->height);
}

unsigned int	Settings::getWidth(void) const
{
	return (this->width);
}


// Setters
void			Settings::setFullscreen(bool value)
{
	this->fullscreen = value;
}

void			Settings::setHeight(unsigned int value)
{
	this->height = value;
}

void			Settings::setWidth(unsigned int value)
{
	this->width = value;
}