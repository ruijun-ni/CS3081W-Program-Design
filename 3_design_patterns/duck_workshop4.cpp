#include <iostream>
using namespace std;

class IDuck {
    public:
        virtual void display() const = 0;
        virtual void swim() const = 0;
        virtual void fly() const = 0;
};

class IMallard : public IDuck {};
class IWoodDuck : public IDuck {};
class IBrantDuck : public IDuck {};

class MidwestMallard : public IMallard {
    public:
        void display() const override {
            cout << "I am a Mallard Duck from the Midwest." << endl;
        }
        void swim() const override {
            cout << "I am a Mallard Duck swimming in the Midwest." << endl;
        }
        void fly() const override {
            cout << "I am a Mallard Duck flying in the Midwest." << endl;
        }
};
class EastCoastMallard : public IMallard {
    public:
        void display() const override {
            cout << "I am a Mallard Duck from the EastCoast." << endl;
        }
        void swim() const override {
            cout << "I am a Mallard Duck swimming in the EastCoast." << endl;
        }
        void fly() const override {
            cout << "I am a Mallard Duck flying in the EastCoast." << endl;
        }
};
class CanadianMallard : public IMallard {
    public:
        void display() const override {
            cout << "I am a Mallard Duck from the Canadian." << endl;
        }
        void swim() const override {
            cout << "I am a Mallard Duck swimming in the Canadian." << endl;
        }
        void fly() const override {
            cout << "I am a Mallard Duck flying in the Canadian." << endl;
        }
};

class MidwestWoodDuck : public IWoodDuck {
    public:
        void display() const override {
            cout << "I am a Wood Duck from the Midwest." << endl;
        }
        void swim() const override {
            cout << "I am a Wood Duck swimming in the Midwest." << endl;
        }
        void fly() const override {
            cout << "I am a Wood Duck flying in the Midwest." << endl;
        }
};
class EastCoastWoodDuck : public IWoodDuck {
    public:
        void display() const override {
            cout << "I am a Wood Duck from the EastCoast." << endl;
        }
        void swim() const override {
            cout << "I am a Wood Duck swimming in the EastCoast." << endl;
        }
        void fly() const override {
            cout << "I am a Wood Duck flying in the EastCoast." << endl;
        }
};
class CanadianWoodDuck : public IWoodDuck {
    public:
        void display() const override {
            cout << "I am a Wood Duck from the Canadian." << endl;
        }
        void swim() const override {
            cout << "I am a Wood Duck swimming in the Canadian." << endl;
        }
        void fly() const override {
            cout << "I am a Wood Duck flying in the Canadian." << endl;
        }
};

class MidwestBrantDuck : public IBrantDuck {
    public:
        void display() const override {
            cout << "I am a Brant Duck from the Midwest." << endl;
        }
        void swim() const override {
            cout << "I am a Brant Duck swimming in the Midwest." << endl;
        }
        void fly() const override {
            cout << "I am a Brant Duck flying the Midwest." << endl;
        }
};
class EastCoastBrantDuck : public IBrantDuck {
    public:
        void display() const override {
            cout << "I am a Brant Duck from the EastCoast." << endl;
        }
        void swim() const override {
            cout << "I am a Brant Duck swimming in the EastCoast." << endl;
        }
        void fly() const override {
            cout << "I am a Brant Duck flying in the EastCoast." << endl;
        }
};
class CanadianBrantDuck : public IBrantDuck {
    public:
        void display() const override {
            cout << "I am a Brant Duck from the Canadian." << endl;
        }
        void swim() const override {
            cout << "I am a Brant Duck swimming in the Canadian." << endl;
        }
        void fly() const override {
            cout << "I am a Brant Duck flying in the Canadian." << endl;
        }
};


class IDuckFactory {
    public:
        virtual IMallard* CreateMallard() = 0;
        virtual IWoodDuck* CreateWoodDuck() = 0;
        virtual IBrantDuck* CreateBrantDuck() = 0;
};

class MidwestDuckFactory : public IDuckFactory {
    public:
        IMallard* CreateMallard() {
            return new MidwestMallard;
        }
        IWoodDuck* CreateWoodDuck() {
            return new MidwestWoodDuck;
        }
        IBrantDuck* CreateBrantDuck() {
            return new MidwestBrantDuck;
        }
};
class EastCoastDuckFactory : public IDuckFactory {
    public:
        IMallard* CreateMallard() {
            return new EastCoastMallard;
        }
        IWoodDuck* CreateWoodDuck() {
            return new EastCoastWoodDuck;
        }
        IBrantDuck* CreateBrantDuck() {
            return new EastCoastBrantDuck;
        }
};
class CanadianDuckFactory : public IDuckFactory {
    public:
        IMallard* CreateMallard() {
            return new CanadianMallard;
        }
        IWoodDuck* CreateWoodDuck() {
            return new CanadianWoodDuck;
        }
        IBrantDuck* CreateBrantDuck() {
            return new CanadianBrantDuck;
        }
};


class Facade {
    private:
        IDuckFactory* factory;
    public:
        Facade(IDuckFactory* f) {
            this->factory = f;
        };
        ~Facade() {
            cout << "deleting facade" << endl;
            delete factory;
        };
        void run() {
            IMallard* duck1 = factory->CreateMallard();
            duck1->display();
            duck1->swim();
            duck1->fly();
            
            IWoodDuck* duck2 = factory->CreateWoodDuck();
            duck2->display();
            duck2->swim();
            duck2->fly();
            
            IBrantDuck* duck3 = factory->CreateBrantDuck();
            duck3->display();
            duck3->swim();
            duck3->fly();

            delete duck1;
            delete duck2;
            delete duck3;
        }
};


int main() {
    MidwestDuckFactory* factory1 = new MidwestDuckFactory();
    Facade* facade1 = new Facade(factory1);
    facade1->run();
    delete facade1;

    EastCoastDuckFactory* factory2 = new EastCoastDuckFactory();
    Facade* facade2 = new Facade(factory2);
    facade2->run();
    delete facade2;

    CanadianDuckFactory* factory3 = new CanadianDuckFactory();
    Facade* facade3 = new Facade(factory3);
    facade3->run();
    delete facade3;

    return 0;
}