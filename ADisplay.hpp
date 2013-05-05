#pragma once


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

	
};

