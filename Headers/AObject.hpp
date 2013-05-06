#ifndef		AObject_HPP
# define	AObject_HPP

// Type definitions
typedef enum
{
	IMAGE,
	CURSOR,
	BLOCK,
	NOTYPE
}	eType;

// Includes
#include "SDL.h"
#include "Ressources.hpp"

class		AObject
{
	// Constructor and destructor
public:
	virtual ~AObject(void) {}

	// Members functions
public:
	virtual void Draw(void) = 0;
	virtual void Update(void) = 0;

	// Getters
public:
	eType				getType(void) const;
	const SDL_Rect &	getPosition(void) const;

	// Setters
public:
	void				setType(eType);
	void				setPosition(const SDL_Rect &);

	// Attributes
protected:
	SDL_Rect			position;
	eType				type;
};

#endif