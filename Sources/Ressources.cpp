#include "Ressources.hpp"

Ressources::Ressources(SDLDisplay *_display, Settings *_settings)
{
	this->colors = new Colors();
	this->settings = _settings;
	this->display = _display;
}

Ressources::~Ressources(void)
{
	delete colors;
}