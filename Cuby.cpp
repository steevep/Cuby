#include "Cuby.hpp"

Cuby::Cuby(void)
{
	// Init Attributes
	this->quit = false;
	this->settings = new Settings("xml configuration file");
	this->display = new SDLDisplay(PROJECT_NAME, this->settings);
	this->display->EnableTransparentWindows();
}

Cuby::~Cuby(void)
{
	std::list<Section *>::iterator it;

	delete this->display;
	delete this->settings;
	it = this->sections.begin();
	while (it != this->sections.end())
	{
		delete (*it);
		it++;
	}
}

void Cuby::UpdateSection(void)
{
	std::list<Section *>::iterator it;

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
	std::list<Section *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == this->current)
			(*it)->DrawObjects();
		it++;
	}
}

Section * Cuby::GetSection(eSection section)
{
	std::list<Section *>::iterator it;

	it = this->sections.begin();
	while (it != this->sections.end())
	{
		if ((*it)->getSection() == section)
			return ((*it));
		it++;
	}
	exit(11);
	return (NULL);
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

void Cuby::CreateBlocks(eSection _section)
{
	Section	*section;
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int vertical_blocks;
	unsigned int horizontal_blocks;

	vertical_blocks = this->display->getHeight() / this->settings->getBlocksize();
	horizontal_blocks = this->display->getWidth() / this->settings->getBlocksize();
	section = this->GetSection(_section);
	if (section != NULL)
		while (y <= vertical_blocks)
		{
			x = 0;
			while (x < horizontal_blocks)
			{
				section->AddObject(new Block(this->settings->getBlocksize(), x, y));
				x++;
			}
			y++;
		}
}

void Cuby::Run(void)
{
	Section *section;

	this->current = SCREENSAVER;
	section = new Section(SCREENSAVER);

	this->sections.push_back(section);
	this->sections.push_back(new Section(HOME));
	this->sections.push_back(new Section(LOGO));

	this->CreateBlocks(SCREENSAVER);
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