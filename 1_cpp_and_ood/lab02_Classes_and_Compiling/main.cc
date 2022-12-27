#include <iostream>
#include <vector>
#include "Duck.h"

void useVector()
{
  // Initializing ducks info
  std::vector<std::vector<std::string>> ducks{
      // {Name, Type, Color}
      {"Unknown", "Unknown", "Unknown"},
      {"King", "Canvasback", "brown-white"},
      {"Mob", "Mallard", "green-white"}};

  // Print all duck info
  for (std::vector<std::string> duck : ducks)
  {
    std::cout << "Name: " << duck.at(0) << std::endl;
    std::cout << "Type: " << duck.at(1) << std::endl;
    std::cout << "Color: " << duck.at(2) << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
}

// uncomment the following if you complete your Duck.cc and Duck.h

void useObject()
{
  // Initializing ducks info using Duck object
  std::vector<Duck *> ducks2;

  // To define new object: new Object("if parameter exist");
  // Create duck using default constructor
  ducks2.push_back(new Duck()); 

  // Create duck by giving name, type, and color
  ducks2.push_back(new Duck("King", "Canvasback", "brown-white"));  

  Duck *mallardMother = new Duck("Whity", "Mallard", "green-white");

  // Create duck by giving name, type, color, and mother info
  ducks2.push_back(new Duck("Mob", "Mallard", "green-white", mallardMother)); 

  // Mother Whity give birth to new duck named White 
  ducks2.push_back(mallardMother->give_birth("White"));

  // Print all duck info
  for (Duck *duck : ducks2)
  {
    duck->print_all();
  }
}


int main(int argc, char **argv)
{
  std::cout << "CSCI3081W Lab 2 - Classes" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "Display using vector" << std::endl;
  std::cout << "=========================" << std::endl;
  useVector();

  // uncomment the following if you complete your Duck.cc and Duck.h
  
  std::cout << "" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "Display using object class" << std::endl;
  std::cout << "=========================" << std::endl;
  useObject(); 
  
}