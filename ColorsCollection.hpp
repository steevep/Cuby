#ifndef		ColorsCollection_HPP
# define	ColorsCollection_HPP

// Type definitions
typedef enum
{
	REDGROUP,
	BLUEGROUP,
	GREENGROUP,
	WHITEGROUP,
	BLACKGROUP,
	ORANGEGROUP,
	YELLOWGROUP,
	PURPLEGROUP,
	NOCOLORGROUP
}	eColorGroup;

typedef enum
{
	RED,
	BLUE,
	GREEN,
	WHITE,
	BLACK,
	ORANGE,
	YELLOW,
	PURPLE,
	NOCOLOR
}	eColor;

// Includes
#include "SDL.h"
#include <list>

class		Color
{
	// Constructor and destructor
public:
	Color(eColorGroup, SDL_Color &);
	~Color(void);

	// Getters
public:
	eColorGroup			getColorGroup(void) const;
	const SDL_Color &	getColor(void) const;

	// Setters
public:
	void				setColor(SDL_Color &);
	void				setColorGroup(eColorGroup);

	// Attributes
private:
	SDL_Color			color;
	eColorGroup			colorGroup;
};

class		ColorsCollection
{
	// Constructor and destructor
public:
	ColorsCollection(void);
	~ColorsCollection(void);

	// Members functions
public:
	void	AddColor(Color *);
	void	AddColors(std::list<Color *> &);
	void	DeleteColors(void);
	void	ClearColors(void);
	Color *	GetRandomColor(void);
	Color *	GetColor(eColorGroup);

	// Attributes
private:
	std::list<Color *>	colors;
};

#endif