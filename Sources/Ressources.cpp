#include "Cuby.hpp"

Ressources *ressources;

Ressources::Ressources(void)
{
	// Create ressources
	this->settings = new Settings("xml configuration file");
	this->display = new SDLDisplay(PROJECT_NAME, this->settings);
	this->colors = new Colors();

	// Init ressources
	this->image_change = true;
	this->offset_height = 0;
	this->offset_width = 0;

	// Init global variable for app ressources
	ressources = this;
}

Ressources::~Ressources(void)
{
	delete colors;
}