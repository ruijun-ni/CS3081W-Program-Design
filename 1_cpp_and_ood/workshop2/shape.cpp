#include <iostream>
#include <math.h>
using namespace std;

class Shape2D {
    protected:
        float width;
        float height;
    public:
        float getHeight() {
            return height;
        }
        void setHeight(float height) {
            this->height = height;
        }
        float getWidth() {
            return width;
        }
        void setWidth(float width) {
            this->width = width;
        }
        virtual float getArea() {
            return 0;
        }
};

class Triangle : public Shape2D {
    public:
        float getArea() {
            return 1/2 * width * height;
        }
};

class Rectangle : public Shape2D {
    public:
        float getArea() {
            return width * height;
        }
};

class Circle : public Shape2D {
    public:
        float getArea() {
            // return 3.14159265358979323846 * width * height * 1/4;
            return M_PI * width * height * 1/4;
        }
};

int main() {
    Circle* testCircle = new Circle();
    testCircle->setWidth(1);
    testCircle->setHeight(1);
    cout << testCircle->getArea();
    return 0;
}