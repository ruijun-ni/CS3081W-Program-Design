#include <string>
#include <iostream>

// base interface
class IComponent {
 public:
  virtual ~IComponent() {}
  virtual std::string Temperature() const = 0;
};

// concrete component
class BaseOutfit : public IComponent {
 public:
  std::string Temperature() const override {
    return "I'm wearing some clothes. ";
  }
};

// base decorator
class Clothes : public IComponent {
 protected:
  IComponent* component_;
 public:
  Clothes(IComponent* component) : component_(component) {
  }
  std::string Temperature() const override {
    return this->component_->Temperature();
  }
};

// concrete component
class Jacket : public Clothes {
 public:
  Jacket(IComponent* component) : Clothes(component) {
  }
  std::string Temperature() const override {
    return Clothes::Temperature() + "I'm also wearing a jacket. ";
  }
};

// concrete component
class HatGloves : public Clothes {
 public:
  HatGloves(IComponent* component) : Clothes(component) {
  }
  std::string Temperature() const override {
    return Clothes::Temperature() + "I am also wearing a hat and gloves. ";
  }
};

void Facade(IComponent* component) {
  std::cout << component->Temperature();
}

int main() {
  IComponent* person = new BaseOutfit;
  Facade(person);
  std::cout << std::endl;

  IComponent* personJacket = new Jacket(person);
  Facade(personJacket);
  std::cout << std::endl;
   
  IComponent* personHatGloves = new HatGloves(person);
  Facade(personHatGloves);
  std::cout << std::endl;
 
  IComponent* personJacketHatGloves = new Jacket(person);
  personJacketHatGloves = new HatGloves(personJacketHatGloves);
  Facade(personJacketHatGloves);
  std::cout << std::endl;
 
  delete person;
  delete personJacket;
  delete personHatGloves;
  delete personJacketHatGloves;
  return 0;
}