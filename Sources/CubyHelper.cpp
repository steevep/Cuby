#include "Cuby.hpp"

void Cuby::UpdateSection(void)
{
	std::list<ASection *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == this->ressources->current_section)
		{
			(*it)->Update();
			(*it)->UpdateObjects();
		}
		it++;
	}
}

void Cuby::DrawSection(void)
{
	std::list<ASection *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == this->ressources->current_section)
		{
			(*it)->Draw();
			(*it)->DrawObjects();
		}
		it++;
	}
}

void Cuby::UpdateObjects(void)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
		(*it)->Update();
		it++;
	}
}

void Cuby::DrawObjects(void)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
		(*it)->Draw();
		it++;
	}
}

void Cuby::HandleEvents(void)
{
	eKey	pressed;
	eEvent	event;

	event = this->ressources->display->HandleEvents();
	pressed = this->ressources->display->PressedKey();
	if (pressed != NOKEY)
	{
		if (pressed == ESC)
			this->quit = true;
	}
	if (event != NOEVENT)
	{
		if (event == QUIT)
			this->quit = true;
	}
}