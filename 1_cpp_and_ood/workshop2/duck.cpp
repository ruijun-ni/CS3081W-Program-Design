#include <iostream>
using namespace std;

class Duck {
    public:
        virtual void display() {
            cout << "I am a Duck" << endl;
        }
        void swim() {
            cout << "I can swim" << endl;
        }
        virtual void fly() {
            cout << "I can fly" << endl;
        }
        virtual void quack() {
            cout << "Quack" << endl;
        }
};

class MallardDuck : public Duck {
    public:
        void display() {
            cout << "I am a MallardDuck" << endl;
        }
};

class RedheadDuck : public Duck {
    public:
        void display() {
            cout << "I am a RedheadDuck" << endl;
        }
};

class RubberDuck : public Duck {
    public:
        void display() {
            cout << "I am a RubberDuck" << endl;
        }
        void fly() {
            cout << "I can not fly" << endl;
        }
        void quack() {
            cout << "Queck" << endl;
        }
};

int main() {
    Duck* testDuck = new RubberDuck();
    testDuck->quack();
    testDuck->swim();
    testDuck->display();
    testDuck->fly();
    return 0;
}