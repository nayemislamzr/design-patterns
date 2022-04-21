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
        std::cout << "Circle\n";
    }
};

class Triangle : public Shape
{
public :
    Triangle() = default;
    virtual void draw() override
    {
        std::cout << "Triangle\n";
    }
};

class Rectangle : public Shape
{
public :
    Rectangle() = default;
    virtual void draw() override
    {
        std::cout << "Rectangle\n";
    }
};

class ShapeFactory
{
public :
    ShapeFactory() = default;
    void setShape(Shape* shape)
    {
        _shapeToUse = shape;
    }
    void createShape()
    {
        _shapeToUse->draw();
    }
private :
    Shape* _shapeToUse;
};

int main()
{
    ShapeFactory* factory = new ShapeFactory();
    factory->setShape(new Circle());
    factory->createShape();

    factory->setShape(new Rectangle());
    factory->createShape();
    
    factory->setShape(new Triangle());
    factory->createShape();
}