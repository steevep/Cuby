#ifndef		ASECTION_HPP
# define	ASECTION_HPP

// Type definitions
typedef enum
{
	HOME,
	LOGO,
	SCREENSAVER
}	eSection;

// Includes
#include <list>
#include "AObject.hpp"
#include "Ressources.hpp"

class		ASection
{
	// Constructor and destructor
public:
	virtual ~ASection(void);

	// Pure members functions
public:
	virtual void Draw(void) = 0;
	virtual void Update(void) = 0;

	// Members functions
public:
	virtual void		AddObjects(std::list<AObject *> &);
	virtual void		AddObject(AObject *);
	virtual void		UpdateObjects(void);
	virtual void		DeleteObjects(void);
	virtual void		ClearObjects(void);
	virtual void		DrawObjects(void);

	// Getters
public:
	virtual eSection	getSection(void) const;
	virtual AObject		*GetObject(unsigned int, unsigned int);

	// Setters
public:
	virtual void setSection(eSection);

	// Attributes
protected:
	eSection				section;
	std::list<AObject *>	objects;
	Ressources				*ressources;
};

#endif