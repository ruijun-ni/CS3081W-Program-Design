#include "Duck.h"
using namespace std;
#include <string>

Duck::Duck() { // Default constructor
    name = "Unknown";
    type = "Unknown";
    color = "Unknown";
    mother = NULL;
}

Duck::Duck(string name, string type, string color) { 
    this->name = name;
    this->type = type;
    this->color = color;
}

Duck::Duck(string name, string type, string color, Duck* mother) { 
    this->name = name;
    this->type = type;
    this->color = color;
    this->mother = mother;
}

Duck* Duck::give_birth(string name) {
    Duck* mother = new Duck(name, this->type, this->color, this);
    return mother;
}

string Duck::get_name() {
    return this->name;
}

string Duck::get_type() {
    return this->type;
}

string Duck::get_color() {
    return this->color;
}

Duck* Duck::get_mother(){
    return this->mother;
}

void Duck::print_all() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Color: " << color << std::endl;
    if(mother){
        std::cout << "Mother's Name: " << mother->get_name() << std::endl;
        std::cout << "Mother's Type: " << mother->get_type() << std::endl;
        std::cout << "Mother's Color: " << mother->get_color() << std::endl;
    } else {
        std::cout << "Mother: Unknown" << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}