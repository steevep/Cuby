#include "Ressources.hpp"

Ressources::Ressources(void)
{
	this->colors = new Colors();
}

Ressources::~Ressources(void)
{
	delete colors;
}