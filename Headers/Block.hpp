#ifndef		BLOCK_HPP
# define	BLOCK_HPP

// Defines
# define	BLOCK_SIZE	40

// Includes
# include	"AObject.hpp"

class		Block : public AObject
{
	// Constructor and destructor
public:
	Block(unsigned int, unsigned int, unsigned int);
	~Block();

  // Members functions
public:
	void			Update(void);
	void			Draw(void);

	// Getters
public:
	bool			GetHidden(void) const;

	// Setters
public:
	void			SetHidden(bool);

    // Attributes
private:
	bool			hidden;
	SDL_Surface  	*image;
};

#endif
