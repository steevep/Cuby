#ifndef		RESSOURCES_HPP
# define	RESSOURCES_HPP

// Includes
#include	"Colors.hpp"
#include	"Settings.hpp"
#include	"SDLDisplay.hpp"

class		Ressources
{
	// Constructor and destructor
public:
	Ressources(void);
	~Ressources(void);

	// Members functions
public:
	int					RandU(int nMin, int nMax);

	// Attributes
public:
	int					current_section;
	Colors				*colors;
	SDLDisplay			*display;
	Settings			*settings;
	bool				image_change;
	// Surfaces			*surfaces;

	unsigned int	offset_height;
	unsigned int	offset_width;

	unsigned int	blocks_total_count;
	unsigned int	blocks_h_count;
	unsigned int	blocks_w_count;
	unsigned int	blocks_sizes;
};

#endif
