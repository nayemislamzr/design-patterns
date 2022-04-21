#include <iostream>
#include <string>

class DrawAPI
{
public :
    DrawAPI() = default;
    virtual void drawCircle(float x, float y, float radius) = 0;
};

class RedCircle : public DrawAPI
{
public :
    RedCircle() = default;
    virtual void drawCircle(float x, float y, float radius) override
    {
        std::cout << "Drawing Red circle at x : " << x << " y : " << y << " of radius : " << radius << ".\n"; 
    }
};

class GreenCircle : public DrawAPI
{
public :
    GreenCircle() = default;
    virtual void drawCircle(float x, float y, float radius) override
    {
        std::cout << "Drawing Green circle at x : " << x << " y : " << y << " of radius : " << radius << ".\n"; 
    }
};

class Shape 
{
public :
    Shape(DrawAPI* drawAPI)
        : thisDrawAPI{drawAPI}
    {

    }
    virtual void draw() = 0;
protected :
    DrawAPI* thisDrawAPI ;
};

class Circle : public Shape
{
public :
    Circle(float x, float y, float radius, DrawAPI* drawAPI)
        : x{x}, y{y} , radius{radius}, Shape{drawAPI}
    {

    }
    virtual void draw() override
    {
        this->thisDrawAPI->drawCircle(x,y,radius);
    }
private :
    float x, y , radius;
};

int main()
{
    // Method - 1
    // DrawAPI* redCircle = new RedCircle();
    // redCircle->drawCircle(12,2,35);

    // Method - 2
    Shape* redCircle = new Circle(12,2,25,new RedCircle());
    redCircle->draw();
}