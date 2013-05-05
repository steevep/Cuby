#ifndef		BLOCK_HPP_
# define	BLOCK_HPP_

// Defines
# define	BLOCK_SIZE	40

// Includes
# include	"AObject.hpp"

class		Block : public AObject
{
	// Constructor and destructor
public:
  Block(unsigned int, unsigned int, unsigned int);
  Block();
  ~Block();

  // Members functions
public:
  void		Update(void);
  void		Draw(void);

    // Attributes
private:
  SDL_Surface  	*image;
};

#endif
