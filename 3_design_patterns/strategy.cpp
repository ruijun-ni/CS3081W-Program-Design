#include <iostream>

class IStrategy {
    public:
        virtual ~IStrategy() {}
        virtual std::string Move() const = 0;
};

class Duck {
    private:
        IStrategy* strategy;
    public:
        Duck(IStrategy* s) {
            this->strategy = s;
        }
        ~Duck() { delete strategy; }
        void set_strategy(IStrategy* s) {
            delete this->strategy;
            this->strategy = s;
        }
        void UseStrategy() const {
            std::string result = this->strategy->Move();
            std::cout << result << std::endl;
        }
};

class Fly : public IStrategy {
    public:
        std::string Move() const override {
            std::string result = "I'm a flying duck.";
            return result;
        }
};

class Swim : public IStrategy {
    public:
        std::string Move() const override {
            std::string result = "I'm a swimming duck.";
            return result;
        }
};

void FacadeFunction() {
    Duck* duck = new Duck(new Fly);
    duck->UseStrategy();
    std::cout << "I'm tired." << std::endl;
    duck->set_strategy(new Swim);
    duck->UseStrategy();
    delete duck;
}

int main() {
    FacadeFunction();
    return 0;
}