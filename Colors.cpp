#include "Colors.hpp"

Color::Color(eColorGroup _colorgroup, SDL_Color & _color)
{
	this->color.r = _color.r;
	this->color.g = _color.g;
	this->color.b = _color.b;
	this->color.unused = _color.unused;
	this->colorGroup = _colorgroup;
}

Color::~Color(void)
{

}

// Getters
eColorGroup			Color::getColorGroup(void) const
{
	return (this->colorGroup);
}

const SDL_Color &	Color::getColor(void) const
{
	return (this->color);
}

// Setters
void				Color::setColor(SDL_Color & _color)
{
	this->color.r = _color.r;
	this->color.g = _color.g;
	this->color.b = _color.b;
	this->color.unused = _color.unused;
}

void				Color::setColorGroup(eColorGroup _colorgroup)
{
	this->colorGroup = _colorgroup;
}

Colors::Colors(void)
{

}

Colors::~Colors(void)
{
	this->DeleteColors();
}

// Members functions
void	Colors::AddColor(Color *)
{

}

void	Colors::AddColors(std::list<Color *> &)
{

}

void	Colors::DeleteColors(void)
{
	std::list<Color *>::iterator it;

	it = this->colors.begin();
	while (it != this->colors.end())
	{
		delete (*it);
		it++;
	}
}

void	Colors::ClearColors(void)
{
	this->colors.clear();
}

Color * Colors::GetRandomColor(void)
{
	std::list<Color *>::iterator it;

	it = this->colors.begin();
	while (it != this->colors.end())
	{
		// return a item randomly
		it++;
	}
	return (NULL);
}

Color *	Colors::GetColor(eColorGroup colorgroup)
{
	std::list<Color *>::iterator it;

	it = this->colors.begin();
	while (it != this->colors.end())
	{
		if ((*it)->getColorGroup() == colorgroup)
			return ((*it));
		it++;
	}
	return (NULL);
}