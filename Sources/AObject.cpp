#include "AObject.hpp"

// Getters
eType				AObject::getType(void) const
{
	return (this->type);
}

const SDL_Rect &	AObject::getPosition(void) const
{
	return (this->position);
}

bool				AObject::GetHidden(void) const
{
	return (this->hidden);
}

// Setters
void				AObject::setType(eType value)
{
	this->type = value;
}

void				AObject::setPosition(const SDL_Rect & value)
{
	this->position.x = value.x;
	this->position.y = value.y;
	this->position.h = value.h;
	this->position.w = value.w;
}

void				AObject::SetHidden(bool value)
{
	this->hidden = value;
}