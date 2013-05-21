#include "Ressources.hpp"

Ressources *ressources;

Ressources::Ressources(SDLDisplay *_display, Settings *_settings)
{
	// Set or create ressources
	this->colors = new Colors();
	this->settings = _settings;
	this->display = _display;

	// Init ressources
	this->offset_height = 0;
	this->offset_width = 0;

	// Init global variable for app ressources
	ressources = this;
}

Ressources::~Ressources(void)
{
	delete colors;
}