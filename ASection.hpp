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
	ASection(eSection, Ressources *);
	~ASection(void);

	// Members functions
public:
	void AddObject(AObject *);
	void AddObjects(std::list<AObject *> &);
	void DeleteObjects(void);
	void ClearObjects(void);
	void DrawObjects(void);
	void UpdateObjects(void);

	// Getters
public:
	eSection getSection(void) const;

	// Setters
public:
	void setSection(eSection);

	// Attributes
protected:
	eSection				section;
	std::list<AObject *>	objects;
	Ressources				*ressources;
};

#endif