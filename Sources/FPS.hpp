#ifndef		FPS_HPP
# define	FPS_HPP

// Includes
# include	"AObject.hpp"

class		FPS : public AObject
{
	// Constructor and destructor
public:
	FPS(bool);
	FPS(void);
	~FPS(void);

  // Pure methods via AObject
public:
	void			Update(void);
	void			Draw(void);

	// Attributes
private:
	int				img;
	int				last;
};

#endif
