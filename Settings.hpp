#ifndef		Settings_HPP
# define	Settings_HPP

// Includes
#include <string>

class		Settings
{
	// Constructor and destructor
public:
	Settings(const std::string &);
	virtual ~Settings(void);

	// Members functions
public:

	// Getters
public:
	bool			getFullscreen(void) const;
	unsigned int	getHeight(void) const;
	unsigned int	getWidth(void) const;

	// Setters
public:
	void			setFullscreen(bool);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	height;
	unsigned int	width;
};

#endif
