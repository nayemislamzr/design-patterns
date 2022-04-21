#include <iostream>

class Shape
{
public :
    Shape() = default;
    virtual void draw() = 0;
};

class Circle : public Shape
{
public :
    Circle() = default;
    virtual void draw() override
    {
        std::cout << "Drawing Circle.\n";
    }
};

class Rectangle : public Shape
{
public :
    Rectangle() = default;
    virtual void draw() override
    {
        std::cout << "Drawing Rectangle.\n";
    }
};

class Square : public Shape
{
public :
    Square() = default;
    virtual void draw() override
    {
        std::cout << "Drawing Square.\n";
    }
};

class ShapeMaker
{
public :
    ShapeMaker()
    {
        circle = new Circle();
        rectangle = new Rectangle();
        square = new Square();
    }
    void drawCircle()
    {
        circle->draw();
    }
    void drawRectangle()
    {
        rectangle->draw();
    }
    void drawSquare()
    {
        square->draw();
    }
private :
    Shape* circle;
    Shape* rectangle;
    Shape* square;
};

int main()
{
    ShapeMaker shapeMaker;
    shapeMaker.drawCircle();
    shapeMaker.drawRectangle();
    shapeMaker.drawSquare();
}