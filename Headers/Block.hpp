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
	Block(unsigned int, unsigned int, unsigned int, bool hidden = true);
	~Block();

  // Pure methods via AObject
public:
	void			Update(void);
	void			Draw(void);
};

#endif
