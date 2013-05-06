/*
** Exception.hpp for Exception in /home/costardrouge
** 
** Made by CostardRouge
** Login   <costardrouge@MonRack>
** 
** Started on  Sat Feb 18 15:06:45 2012 CostardRouge
** Last update Tue May  8 18:10:23 2012 steeve pommier
*/

#ifndef		Exception_HPP
# define	Exception_HPP

#include	<string>
#include	<exception>

class		Exception : public std::exception
{
private:
  std::string	_err;

public:
  Exception(std::string const &) throw();
  virtual ~Exception() throw();
  
  virtual const char *what() const throw();
};

#endif		// Exception_HPP_
