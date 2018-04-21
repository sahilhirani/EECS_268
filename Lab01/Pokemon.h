#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

class Pokemon
{
public: // ALL Comments for this section in cpp file
  Pokemon(); //initializes variables
  std::string getAname();
  std::string getJname();
  int getId();
  void setAname(std::string aname);
  void setJname(std::string jname);
  void setId(int id);

private: // Member variables for american name japanese name and Pokemon ID
  std::string m_aname;
  std::string m_jname;
  int m_id;

};
#endif
