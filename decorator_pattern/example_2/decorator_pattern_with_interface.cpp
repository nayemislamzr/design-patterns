#include <iostream>

class Shape
{
public :
    Shape() = default;
    Shape(Shape* shapeBehave)
        : _shapeBehave{shapeBehave}
    {

    }
    virtual void draw()
    {
        _shapeBehave->draw();
    }
private :
    Shape* _shapeBehave;
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
        std::cout << "Circle \n";
    }
};

class Rectangle : public Shape
{
public :
    Rectangle() = default;
    virtual void draw() override
    {
        std::cout << "Rectangle \n";
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
    Shape* basicCircle = new Shape(new Circle());
    Shape* basicRectange = new Shape(new Rectangle());
    basicCircle->draw();
    basicRectange->draw();

    ShapeDecorator* redCircle = new RedShapeDecorator(basicCircle);
    ShapeDecorator* greenRectangle = new GreenShapeDecorator(basicRectange);
    redCircle->draw();
    greenRectangle->draw();

    ShapeDecorator* redGreenRectangle = new RedShapeDecorator(greenRectangle);
    redGreenRectangle->draw();
}