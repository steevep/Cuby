#ifndef		SCREENSAVER_HPP
# define	SCREENSAVER_HPP

// Includes
#include "Block.hpp"
#include "ASection.hpp"

class		ScreenSaver : public ASection
{
	// Constructor and destructor
public:
	ScreenSaver(Ressources *_ressources);
	~ScreenSaver(void);

	// Members functions (ASection)
public:
	virtual void Draw(void);
	virtual void Update(void);

	// Attributes
public:
	void		CreateBlocks(void);
};

#endif