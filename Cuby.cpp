#include "Cuby.hpp"

Cuby::Cuby(void)
{
	std::cout << PROJECT_NAME << " Constructor" << std::endl;

	// Init Attributes
	this->quit = false;
	this->settings = new Settings("xml configuration file");
	this->display = new SDLDisplay(PROJECT_NAME, this->settings);
}


Cuby::~Cuby(void)
{
	delete this->settings;
	delete this->display;
	std::cout << PROJECT_NAME << " Destructor" << std::endl;
}


void Cuby::Run(void)
{
	std::cout << PROJECT_NAME << " Running..." << std::endl;
	while (!this->quit)
	{
		_sleep(1);
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
		std::cout << PROJECT_NAME << " " << e.what() << std::endl;
		exit(1);
	}
	delete core;
	return (0);
}