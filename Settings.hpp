#ifndef		SETTINGS_HPP
# define	SETTINGS_HPP

// Includes
#include <string>

class		Settings
{
	// Constructor and destructor
public:
	Settings(const std::string &);
	~Settings(void);

	// Members functions
public:

	// Getters
public:
	bool			getFullscreen(void) const;
	unsigned int	getBlocksize(void) const;
	unsigned int	getHeight(void) const;
	unsigned int	getWidth(void) const;

	// Setters
public:
	void			setBlocksize(unsigned int);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);
	void			setFullscreen(bool);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	blocksize;
	unsigned int	height;
	unsigned int	width;
	unsigned int	delay;
};

#endif