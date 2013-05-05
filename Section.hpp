#ifndef		Section_HPP
# define	Section_HPP

// Type definitions
typedef enum
{
	HOME,
	LOGO,
	SCREENSAVER
}	eSection;

// Includes
#include <list>
#include "Object.php"

class		Section
{
	// Constructor and destructor
public:
	Section(eSection);
	~Section(void);

	// Members functions
public:
	void AddObject(Object *);
	void AddObjects(const std::list<Object *> &);
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
private:
	eSection			section;
	unsigned int		height;
	unsigned int		width;
	std::list<Object *> objects;
};

#endif
