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

class IDisplay
{
	// Constructor and destructor
public:
	IDisplay(void);
	virtual ~IDisplay(void);

	// Members functions
public:
	void init(void);
	void refresh(void);
	eKey pressedKey(void);

	// Attributes
private:
	unsigned int	height;
	unsigned int	widtht;
};

