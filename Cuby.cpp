#include "Cuby.hpp"

Cuby::Cuby(void)
{
	// Init Attributes
	this->quit = false;
	this->ressources = new Ressources();

	// Doing some stuff
	// this->ressources->display->EnableTransparentWindow();
}

Cuby::~Cuby(void)
{
	std::list<ASection *>::iterator it;
	std::list<AObject *>::iterator	it_ob;

	delete this->ressources;
	it = this->sections.begin();
	it_ob = this->objects.begin();
	while (it != this->sections.end())
	{
		delete (*it);
		it = this->sections.erase(it);
		it++;
	}
	while (it_ob != this->objects.end())
	{
		delete (*it_ob);
		it_ob = this->objects.erase(it_ob);
		it++;
	}
}

void Cuby::Run(void)
{
	// Push Objects / Sections
	this->objects.push_back(new FPS(false));
	this->ressources->current_section = SCREENSAVER;
	this->sections.push_back(new ScreenSaver(this->ressources));

	// Runtime loop
	while (!this->quit)
	{
		this->ressources->display->Refresh();
		this->ressources->display->Clear();
		this->HandleEvents();
		this->UpdateObjects();
		this->UpdateSection();
		this->DrawSection();
		this->DrawObjects();
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
