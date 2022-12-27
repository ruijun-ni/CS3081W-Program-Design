#include <iostream>
using namespace std;
class IDuck {
  public:
    virtual void display() const = 0;
    virtual void swim() const = 0;
    virtual void fly() const = 0;
};

class IMallard: public IDuck{};
class IBrantDuck: public IDuck{};
class IWoodDuck: public IDuck{};

class MidWestMallard : public IMallard{
  public:
    void display() const override{
      cout<<"I am a Mallard Duck from the Midwest"<<endl;
    }
    void swim() const override{
      cout<<"I am a Mallard Duck swiming in the Midwest"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a Mallard Duck flying in the Midwest"<<endl;
    }
};
class EastCoastMallard : public IMallard{
  public:
    void display() const override{
      cout<<"I am a Mallard Duck from the EastCosat"<<endl;
    }
    void swim() const override{
      cout<<"I am a Mallard Duck swiming in the EastCosat"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a Mallard Duck flying in the EastCosat"<<endl;
    }
};

class CanadianMallard : public IMallard{
  public:
    void display() const override{
      cout<<"I am a Mallard Duck from the Canadian"<<endl;
    }
    void swim() const override{
      cout<<"I am a Mallard Duck swiming in the Canadian"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a Mallard Duck flying in the Canadian"<<endl;
    }
};

class MidWestWoodDuck : public IWoodDuck{
  public:
    void display() const override{
      cout<<"I am a wood Duck from the Midwest"<<endl;
    }
    void swim() const override{
      cout<<"I am a wood Duck swiming in the Midwest"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a wood Duck flying in the Midwest"<<endl;
    }
};
class EastCoastWoodDuck : public IWoodDuck{
  public:
    void display() const override{
      cout<<"I am a wood Duck from the EastCosat"<<endl;
    }
    void swim() const override{
      cout<<"I am a wood Duck swiming in the EastCosat"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a wood Duck flying in the EastCosat"<<endl;
    }
};

class CanadianWoodDuck : public IWoodDuck{
  public:
    void display() const override{
      cout<<"I am a wood Duck from the Canadian"<<endl;
    }
    void swim() const override{
      cout<<"I am a wood Duck swiming in the Canadian"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a wood Duck flying in the Canadian"<<endl;
    }
};

class MidWestBrantDuck : public IBrantDuck{
  public:
    void display() const override{
      cout<<"I am a brant Duck from the Midwest"<<endl;
    }
    void swim() const override{
      cout<<"I am a brant Duck swiming in the Midwest"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a brant Duck flying in the Midwest"<<endl;
    }
};
class EastCoastBrantDuck : public IBrantDuck{
  public:
    void display() const override{
      cout<<"I am a brant Duck from the EastCosat"<<endl;
    }
    void swim() const override{
      cout<<"I am a brant Duck swiming in the EastCosat"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a brant Duck flying in the EastCosat"<<endl;
    }
};

class CanadianBrantDuck : public IBrantDuck{
  public:
    void display() const override{
      cout<<"I am a brant Duck from the Canadian"<<endl;
    }
    void swim() const override{
      cout<<"I am a brant Duck swiming in the Canadian"<<endl;
    }
    virtual void fly() const override{
      cout<<"I am a brant Duck flying in the Canadian"<<endl;
    }
};

class IDuckfactory{
  public:
    virtual IMallard* CreateMallard () = 0;
    virtual IWoodDuck* CreateWoodDuck () = 0;
    virtual IBrantDuck* CreateBrantDuck () = 0;
};

class EastCoastDuckFactory: public IDuckfactory {
public:
  IMallard* CreateMallard (){
    return new EastCoastMallard;
  }
  IWoodDuck* CreateWoodDuck (){
    return new EastCoastWoodDuck;
  }
  IBrantDuck* CreateBrantDuck (){
    return new EastCoastBrantDuck;
  }
};

class MidWestDuckFactory: public IDuckfactory{
public:  
  IMallard* CreateMallard (){
    return new MidWestMallard;
  }
  IWoodDuck* CreateWoodDuck (){
    return new MidWestWoodDuck;
  }
  IBrantDuck* CreateBrantDuck (){
    return new MidWestBrantDuck;
  }
};

class CanadianDuckFactory: public IDuckfactory{
public:
  IMallard* CreateMallard (){
    return new CanadianMallard;
  }
  IWoodDuck* CreateWoodDuck (){
    return new CanadianWoodDuck;
  }
  IBrantDuck* CreateBrantDuck (){
    return new CanadianBrantDuck;
  }
};

class Facade{
  private:
    IDuckfactory* factory;
  public:
    Facade(IDuckfactory* f){factory = f;}
    ~Facade(){delete factory;}
    void run(){
      IMallard* a = factory->CreateMallard();
      IWoodDuck* b = factory->CreateWoodDuck();
      IBrantDuck* c = factory->CreateBrantDuck();
      a->display();
      a->swim();
      a->fly();
      b->display();
      b->swim();
      b->fly();
      c->display();
      c->swim();
      c->fly();
      delete a;
      delete b;
      delete c;
    }
};

int main(){
  Facade faca(new EastCoastDuckFactory());
  faca.run();
  Facade facb(new MidWestDuckFactory());
  facb.run();
  Facade facc(new CanadianDuckFactory());
  facc.run();
}
