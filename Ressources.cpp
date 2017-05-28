#include "Cuby.hpp"

Ressources *ressources;

Ressources::Ressources(void)
{
	// Create ressources
	this->settings = new Settings("xml configuration file");
	this->display = new SDLDisplay(PROJECT_NAME, this->settings);
	this->colors = new Colors();

	// Init ressources
	this->image_change = false;
	this->offset_height = 0;
	this->offset_width = 0;

	// Init global variable for app ressources
	ressources = this;

	// Set some variables I'll need later
	this->blocks_sizes = this->settings->getBlocksize();
	this->blocks_h_count = this->display->getHeight() / this->settings->getBlocksize();
	this->blocks_w_count = this->display->getWidth() / this->settings->getBlocksize();
}

Ressources::~Ressources(void)
{
	delete this->colors;
	delete this->display;
	delete this->settings;
}

int Ressources::RandU(int nMin, int nMax)
{
    return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
}
