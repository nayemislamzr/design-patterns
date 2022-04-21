#include <iostream>

class Shape
{
public :
    Shape() = default;
    virtual void draw() = 0;
};

class ShapeDecorator : public Shape
{
public :
    ShapeDecorator(Shape* shape)
        : _shape{shape}
    {

    }
    virtual void draw() = 0;
protected :
    Shape* _shape;
};

class Circle : public Shape
{
public :
    Circle() = default;
    virtual void draw() override
    {
        std::cout << "Circle drawn.\n";
    }
};

class Rectangle : public Shape
{
public :
    Rectangle() = default;
    virtual void draw() override
    {
        std::cout << "Rectangle drawn.\n";
    }
};

class RedShapeDecorator : public ShapeDecorator
{
public :
    RedShapeDecorator(Shape* shape)
        : ShapeDecorator{shape}
    {

    }
    virtual void draw() override
    {
        std::cout << "Red ";
        this->_shape->draw();
    }
};

class GreenShapeDecorator : public ShapeDecorator
{
public :
    GreenShapeDecorator(Shape* shape)
        : ShapeDecorator{shape}
    {

    }
    virtual void draw() override
    {
        std::cout << "Green ";
        this->_shape->draw();
    }
};

int main()
{
    Shape* basicCircle = new Circle();
    Shape* basicRectange = new Rectangle();
    basicCircle->draw();
    basicRectange->draw();

    ShapeDecorator* redCircle = new RedShapeDecorator(basicCircle);
    ShapeDecorator* greenRectangle = new GreenShapeDecorator(basicRectange);
    redCircle->draw();
    greenRectangle->draw();
}