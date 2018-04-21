#include "Pokemon.h"

Pokemon::Pokemon() //Constructor inistiallizes variables
{
  m_aname = " ";
  m_jname = " ";
  m_id = 0;
}

void Pokemon::setAname(std::string aname) // Sets american name
{
  m_aname = aname;
}

void Pokemon::setJname(std::string jname) // Sets japanese name
{
  m_jname = jname;
}

void Pokemon::setId(int id) // Sets Pokemon ID
{
  m_id = id;
}

std::string Pokemon::getAname() // Gets American Name
{
  return(m_aname);
}

std::string Pokemon::getJname() // Gets Japanese Name
{
  return(m_jname);
}

int Pokemon::getId() // Gets Pokemon ID
{
  return(m_id);
}
