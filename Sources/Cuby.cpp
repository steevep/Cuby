#include "Cuby.hpp"

Cuby::Cuby(void)
{
	// Init Attributes
	this->quit = false;
	this->settings = new Settings("xml configuration file");
	this->display = new SDLDisplay(PROJECT_NAME, this->settings);
	this->ressources = new Ressources(this->display, this->settings);

	// Doing some stuff
	this->display->EnableTransparentWindows();
}

Cuby::~Cuby(void)
{
	std::list<ASection *>::iterator it;

	delete this->display;
	delete this->settings;
	delete this->ressources;
	it = this->sections.begin();
	while (it != this->sections.end())
	{
		delete (*it);
		it++;
	}
}

void Cuby::UpdateSection(void)
{
	std::list<ASection *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == this->current)
			(*it)->UpdateObjects();
		it++;
	}
}

void Cuby::DrawSection(void)
{
	std::list<ASection *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == this->current)
			(*it)->DrawObjects();
		it++;
	}
}

void Cuby::HandleEvents(void)
{
	eKey	pressed;
	eEvent	event;

	event = this->display->HandleEvents();
	pressed = this->display->PressedKey();
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

void Cuby::Run(void)
{
	this->current = SCREENSAVER;
	this->sections.push_back(new ScreenSaver(this->ressources));
	while (!this->quit)
	{
		this->display->Clear();
		this->HandleEvents();
		this->UpdateSection();
		this->DrawSection();
		this->display->Refresh();
	}
}

int main(int ac, char **av)
{
	Cuby	*core;

	try
	{
		core = new Cuby();
		core->Run();
	}
	catch (const Exception & e)
	{
		std::cerr << PROJECT_NAME << " " << e.what() << std::endl;
		exit(1);
	}
	delete core;
	return (0);
}