#include "Executive.h"

Executive::Executive(std::string filename) //Sends input filename to function to be put into an array of pokemon
{
  filetoPoke(filename);
}

void Executive::filetoPoke(std::string filename) //Creates array of pokemon
{
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {
    m_isopen = true;//if th efile opened this becomes true so that the run function knows the fie was able to be opened
    inFile >> m_size;
    poke1 = new Pokemon[m_size];
    std::string aname = "";
    std::string jname = "";
    std::string idstring = "";
    int iD = 0;
    std::getline(inFile, aname); // Takes in an empty line after the size
    for(int i = 0; i < m_size; i++) //
    {
      std::getline(inFile, aname, ','); //inputs data stops at ','
      std::getline(inFile, idstring, ',');
      std::getline(inFile, jname);
      poke1[i].setAname(aname);
      poke1[i].setJname(jname);
      iD = std::stoi(idstring);
      poke1[i].setId(iD);
    }
    inFile.close();
  }
  else
  {
    m_isopen = false;
  }
}

void Executive::run() // RUNS EVERYTHING!
{
  if(m_isopen == true) //Was the file able to be opened?
  {
    int option = 0;
    while(option != 5)
    {
      std::cout << "\n";
      std::cout << "\033[1;34mWelcome to the POKEDEX!!\033[0m\n"; //COLORED WELCOME SIGN
      std::cout << "--------------------------------------------\n";
      std::cout << "\t\t\t Menu:\n";//MENU
      std::cout << "1) Select A Pokemon ID To Show\n"
                <<  "2) Print All Pokemon Within ID Range\n"
                <<  "3) Write All Japanese Names To A File\n"
                <<  "4) Print All Pokemon That have a Certain Beginning Letter\n"
                <<  "5) Quit Program\n";
      std::cout << "\n";
      std::cout << "Enter Selection: ";
      std::cout << "\n";
      std::cin >> option;//User selects what he/she wants to do
      if(option == 1)//Prints out the pokemon with a user defined ID
      {
        std::cout << "Option 1 Selected\n";
        int ID;
        std::cout << "Enter Pokemon ID: ";
        std::cin >> ID;
        std::cout << "\n";
        for(int i = 0; i < m_size; i++)
        {
          if(poke1[i].getId() == ID)
          {
            std::cout << "Pokemon #" << poke1[i].getId() <<": "<< poke1[i].getAname() << " (USA), "<< poke1[i].getJname() <<" (JPN) \n";
          }
        }
        std::cout << "\n";
      }
      else if(option == 2) //Prints out a range of ID numbers chosen by the User
      {
        std::cout << "Option 2 Selected\n";
        int small = 0;
        int big = 0;
        char good;
        char good2;
        while(good != 'y')//both while loops make sure that the numbers the user enters make sense
        {
          std::cout << "Enter Smallest ID: ";
          std::cin >> small;
          if((small < 0) || (small > m_size))
          {
            good = 'n';
            std::cout << "Number entered is either too small or too big please stay within the range of the number of Pokemon 0 to " << m_size<< "\n";
          }
          else
          {
            good = 'y';
          }
        }
        while(good2 != 'y')
        {
          std::cout << "Enter Largest ID: ";
          std::cin >> big;
          if(((big < 0) || (big > m_size)) && (big >= small))
          {
            good2 = 'n';
            std::cout << "Number entered is either too small or too big please stay within the range of the number of Pokemon 0 to " << m_size<< "\n";
            std::cout << "Also needs to be bigger than or equal to the smaller number entered above " << small << "\n";
          }
          else
          {
            good2 = 'y';
          }
        }

        std::cout << "\n";
        for(int i = 0; i < m_size; i++)
        {
          if((poke1[i].getId() >= small) && (poke1[i].getId() <= big))
          {
            std::cout << "Pokemon #" << poke1[i].getId() <<": "<< poke1[i].getAname() << " (USA), "<< poke1[i].getJname() <<" (JPN) \n";
          }
        }
        std::cout << "\n";
      }
      else if(option == 3) //creates an output file with pokemon japanese names that has the name that the user enters
      {
        std::cout << "Option 3 Selected\n";
        std::string userFile;
        std::cout << "Please Enter a Filename (Don't Forget .txt): ";
        std::cin >> userFile;
        std::ofstream outFile;
        outFile.open(userFile);
        for(int i = 0; i < m_size; i++)
        {
          outFile << poke1[i].getJname();
          outFile << "\n";
        }
        outFile.close();
        std::cout << "File Created!\n";
        std::cout << "\n";
      }
      else if(option == 4) // Prints out the pokemon that begins with the letter entered by the user
      {
        std::cout << "Option 4 Selected\n";
        std::cout << "Which Letter Would You Like To Search For: ";
        char letter;
        std::cin >> letter;
        letter = toupper(letter); // automatically capitolizes whatever the user enters
        char anamel;
        std::string name;
        std::cout << "\n";
        for(int i = 0; i < m_size; i++)
        {
          name = poke1[i].getAname();
          anamel = name[0];
          if(anamel == letter)
          {
            std::cout << "Pokemon #" << poke1[i].getId() <<": "<< poke1[i].getAname() << " (USA), "<< poke1[i].getJname() <<" (JPN) \n";
          }
        }
        std::cout << "\n";
      }
      else if(option == 5)//exits the program
      {
        std::cout << "Option 5 Selected\n";
        std::cout << "--------------------------------------------\n";
        std::cout << "\033[1;34mThank You For Using The POKEDEX, Until Next Time Trainer!\033[0m\n\n";
      }
      else
      {
        std::cout << "Not A Valid Selection, Please Try Again\n";
      }
    }
  }
  else//if the file was not able to be opened this error prints out
  {
    std::cout << "ERROR FILENAME NOT VALID! ENDING PROGRAM!\n\n";
  }
}

Executive::~Executive()//deletes pokemone array
{
  delete[] poke1;
}
