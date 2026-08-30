#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;

    void info() {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle." << endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;

    circle.draw();
    rectangle.draw();

    circle.info();

    return 0;
}