#pragma once
// Defines
#define BLOCK	40

// Type definitions
typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	ESC
}	eKey;

class ADisplay
{
	// Constructor and destructor
public:
	virtual ~ADisplay(void) {}

	// Members functions
public:
	virtual void init(void) = 0;
	virtual void refresh(void) = 0;
	virtual eKey pressedKey(void) = 0;

	// Getters
	bool			getFullscreen(void);
	unsigned int	getHeight(void);
	unsigned int	getWidth(void);

	// Setters
	void			setFullscreen(bool);
	void			setHeight(unsigned int);
	void			setWidth(unsigned int);

	// Attributes
private:
	bool			fullscreen;
	unsigned int	height;
	unsigned int	width;
};

