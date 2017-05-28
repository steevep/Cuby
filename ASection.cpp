#include "ASection.hpp"

ASection::~ASection(void)
{
  std::list<AObject *>::iterator it;
  this->DeleteObjects();
}

// Members functions
void ASection::AddObject(AObject *item)
{
	this->objects.push_back(item);
}

void ASection::AddObjects(std::list<AObject *> & items)
{
  std::list<AObject *>::iterator it;

  it = items.begin();
  while (it != items.end())
	{
	  this->objects.push_back(*it);
      it++;
    }	
}

void ASection::DeleteObjects(void)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
      delete (*it);
      it++;
    }	
}

void ASection::ClearObjects(void)
{
	this->objects.clear();
}

void ASection::DrawObjects(void)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
      (*it)->Draw();
      it++;
    }	
}

void ASection::UpdateObjects(void)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
      (*it)->Update();
      it++;
    }	
}

AObject		*ASection::GetObject(unsigned int x, unsigned int y)
{
	std::list<AObject *>::iterator it;

	it = this->objects.begin();
	while (it != this->objects.end())
	{
		if(((*it)->getPosition().x == x) && ((*it)->getPosition().y == y))
			return (*it);
		it++;
    }
	return (NULL);
}

// Getters
eSection ASection::getSection(void) const
{
	return (this->section);
}

// Setters
void ASection::setSection(eSection value)
{
	this->section = value;
}