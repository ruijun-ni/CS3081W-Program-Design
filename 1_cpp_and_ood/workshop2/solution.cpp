#include <iostream>

class Duck {
    public:
        virtual void display() {std::cout<<"I am a Duck."<<std::endl;}
        void swim() {std::cout << "I can swim!" << std::endl;}
        virtual void fly() {std::cout << "I can fly!" << std::endl;}
        virtual void quack() {std::cout << "Quack" << std::endl;}
};

class MallardDuck : public Duck {
    public:
        void display() {std::cout<<"I am a Mallard Duck."<<std::endl;}
};

class RubberDuck : public Duck {
    public:
        void display() {std::cout<<"I am a Mallard Duck."<<std::endl;}
        void quack() {std::cout <<"Squeak!" <<std::endl;}
        void fly() {std::cout << "I can't fly!" << std::endl;}
};

class RedheadDuck : public Duck {
    public:
        void display() {std::cout<<"I am a Redhead Duck."<<std::endl;}
};

class Shape {
    protected:
        double w;
        double h;
    public:
        double getWidth(){return w;}
        double getHeight(){return h;}
        void setWidth(double width){w=width;}
        void setHeight(double height){h=height;}
        virtual double getArea() = 0;
};

class Rectangle : public Shape {
    public:
        double getArea(){
            int a = w*h;
            return a;
        }
};

class Triangle : public Shape {
    public:
        double getArea(){return w*h*.5;}
};

int main(){

    // can't do this:
    // Shape* shape = new Shape();
    // because it is abstract from the pure virtual function

    Rectangle* r = new Rectangle();
    r->setHeight(3);
    r->setWidth(4);
    Triangle* t = new Triangle();
    t->setHeight(3);
    t->setWidth(4);
    std::cout<<"Rectangle's area: "<<r->getArea()<<std::endl;
    std::cout<<"Triangle's area: "<<t->getArea()<<std::endl;

    Duck duck;
    std::cout << "//Duck duck" <<std::endl;
    duck.quack();

    Duck someDuck = RubberDuck();
    std::cout << "//Duck someDuck = RubberDuck();"<<std::endl;
    someDuck.quack();

    Duck* someDuck2 = new RubberDuck();
    std::cout << "//Duck* someDuck2 = new RubberDuck();"<<std::endl;
    someDuck2->quack();

    RubberDuck rubberDuck = RubberDuck();
    std::cout << "//RubberDuck rubberDuck = RubberDuck();"<<std::endl;
    rubberDuck.quack();

}
