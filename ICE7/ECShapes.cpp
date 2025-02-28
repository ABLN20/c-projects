class Shape 
{
public:
    virtual double CalcArea() const = 0;
};

template <typename T>
class Rectangle : public Shape {
public:
    Rectangle(T width, T height) : width(width), height(height) {}

    Rectangle(T x1, T y1, T x2, T y2) {
        width = x2 - x1;
        height = y2 - y1;
    }

    double CalcArea() const override {
        return width * height;
    }

private:
    T width;
    T height;
};

template <typename T>
class Square : public Rectangle<T> {
public:
    Square(T sideLength) : Rectangle<T>(sideLength, sideLength) {}
};