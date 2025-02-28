

#include <iostream>
#include <string>
#include <cmath>
#include <vector> 

// Base class: Shape
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {}

    // TODO: Declare a virtual destructor
    virtual ~Shape() {}
    // TODO: Declare a pure virtual function called area()
    virtual double area() const = 0;
    // TODO: Declare a pure virtual function called perimeter()
    virtual double perimeter() const = 0;
    // TODO: Implement a non-virtual function called getColor() that returns the color
    std::string getColor() const
    {
        return color;
    }
    // TODO: Declare a virtual function called display()
    virtual void display() const
    {
        std::cout << "Color: " << color;
    }
};

// TODO: Implement a derived class called Circle
// It should have a private member variable for radius

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}

    double area() const override 
    {
        return 3.14 * radius * radius;
    }

    double perimeter() const override 
    {
        return 2 * 3.14 * radius;
    }

    void display() const override 
    {
        Shape::display();
        std::cout << ", Shape: Circle, Radius: " << radius
                  << ", Area: " << area()
                  << ", Perimeter: " << perimeter();
    }
};

// TODO: Implement a derived class called Rectangle
// It should have private member variables for width and height
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(const std::string& c, double w, double h) : Shape(c), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        Shape::display();
        std::cout << ", Shape: Rectangle, Width: " << width
                  << ", Height: " << height
                  << ", Area: " << area()
                  << ", Perimeter: " << perimeter();
    }
};

// TODO: Implement a derived class called Square that inherits from Rectangle
// Override necessary functions to ensure a square always has equal sides
class Square : public Rectangle 
{
public:
    Square(const std::string& c, double side) : Rectangle(c, side, side) {}

    void display() const override 
    {
        Shape::display();
        std::cout << ", Shape: Square, Side: " << perimeter() / 4
                  << ", Area: " << area()
                  << ", Perimeter: " << perimeter();
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle("Red", 5.0));
    shapes.push_back(new Rectangle("Blue", 4.0, 6.0));
    shapes.push_back(new Square("Green", 3.0));

    for (const auto& shape : shapes) {
        shape->display();
        std::cout << std::endl;
    }

    // Clean up
    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}