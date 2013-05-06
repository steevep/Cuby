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

	// Members functions
public:
	virtual void AddObject(AObject *);
	virtual void AddObjects(std::list<AObject *> &);
	virtual void DeleteObjects(void);
	virtual void ClearObjects(void);
	virtual void DrawObjects(void);
	virtual void UpdateObjects(void);

	// Getters
public:
	virtual eSection getSection(void) const;

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