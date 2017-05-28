/*
** Exception.cpp for Exception in /home/costardrouge
** 
** Made by CostardRouge
** Login   <costardrouge@MonRack>
** 
** Started on  Sat Feb 18 15:06:22 2012 CostardRouge
** Last update Wed Mar 14 13:36:49 2012 steeve pommier
*/

#include	"Exception.hpp"

Exception::Exception(const std::string & err) throw()
{
  this->_err = err;
}

Exception::~Exception() throw()
{
  
}

const char *Exception::what() const throw()
{
  return (this->_err.c_str());
}
