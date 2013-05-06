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

	// Attributes
public:
	void		CreateBlocks(void);
};

#endif