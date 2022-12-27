#include <string>
#include <iostream>

class IChair {
 public:
  virtual ~IChair(){};
  virtual std::string UsefulFunctionA() const = 0;
};

class VictorianChair : public IChair {
 public:
  std::string UsefulFunctionA() const override {
    return "I am VictorianChair.";
  }
};

class ModernChair : public IChair {
  std::string UsefulFunctionA() const override {
    return "I am ModernChair.";
  }
};

class ISofa {

 public:
  virtual ~ISofa(){};
  virtual std::string UsefulFunctionB() const = 0;
  virtual std::string AnotherUsefulFunctionB(const IChair &collaborator) const = 0;
};

class VictorianSofa : public ISofa {
 public:
  std::string UsefulFunctionB() const override {
    return "I am VictorianSofa.";
  }

  std::string AnotherUsefulFunctionB(const IChair &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the VictorianSofa collaborating with ( " + result + " )";
  }
};

class ModernSofa : public ISofa {
 public:
  std::string UsefulFunctionB() const override {
    return "I am ModernSofa.";
  }

  std::string AnotherUsefulFunctionB(const IChair &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the ModernSofa collaborating with ( " + result + " )";
  }
};

class IFurnitureFactory {
 public:
  virtual IChair *CreateChair() const = 0;
  virtual ISofa *CreateSofa() const = 0;
};

class VictorianFurnitureFactory : public IFurnitureFactory {
 public:
  IChair *CreateChair() const override {
    return new VictorianChair();
  }
  ISofa *CreateSofa() const override {
    return new VictorianSofa();
  }
};

class ModernFurnitureFactory : public IFurnitureFactory {
 public:
  IChair *CreateChair() const override {
    return new ModernChair();
  }
  ISofa *CreateSofa() const override {
    return new ModernSofa();
  }
};

void ClientCode(const IFurnitureFactory &factory) {
  const IChair *product_a = factory.CreateChair();
  const ISofa *product_b = factory.CreateSofa();
  std::cout << product_b->UsefulFunctionB() << "\n";
  std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
  delete product_a;
  delete product_b;
}

int main() {
  std::cout << "Client: Testing client code with the Victorian factory type:\n";
  VictorianFurnitureFactory *f1 = new VictorianFurnitureFactory();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the Modern factory type:\n";
  ModernFurnitureFactory *f2 = new ModernFurnitureFactory();
  ClientCode(*f2);
  delete f2;
  return 0;
}