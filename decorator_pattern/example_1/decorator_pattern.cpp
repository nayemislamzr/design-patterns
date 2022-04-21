#include <iostream>

class Bevarage // abstract class for base material
{
public :
    Bevarage() = default;
    virtual int cost() = 0;
};

class AddonDecorator : public Bevarage // abstract class for decorators
{
public :
    AddonDecorator(Bevarage* bevarage)
        : _bevarage{bevarage}
    {

    }
    virtual int cost() = 0;
protected :
    Bevarage* _bevarage;
};

class Decaf : public Bevarage
{
public :
    Decaf() = default;
    virtual int cost() override
    {
        return 1; // price of Decaf coffee is $1
    }
};

class Espresso : public Bevarage
{
public :
    Espresso() = default;
    virtual int cost() override
    {
        return 2; // price of Espresso coffee is $2
    }
};

class Caramel : public AddonDecorator
{
public :
    Caramel(Bevarage* bevarage)
        : AddonDecorator{bevarage}
    {

    }
    virtual int cost() override
    {
        return this->_bevarage->cost() + 1; // the price of it's relative base + $1 for caramel
    }
};

class Soy : public AddonDecorator
{
public :
    Soy(Bevarage* bevarage)
        : AddonDecorator{bevarage}
    {

    }
    virtual int cost() override
    {
        return this->_bevarage->cost() + 2; // the price of it's reletive base + $2 for soy
    }
};

int main()
{
    Bevarage* basicDecaf = new Decaf();
    Bevarage* basicEspresso = new Espresso();
    std::cout << "Cost of Basic Decaf : " << basicDecaf->cost() << '\n'
    << "Cost of Basic Espresso : " << basicEspresso->cost() << '\n';

    AddonDecorator* carameledDecaf = new Caramel(basicDecaf);
    AddonDecorator* carameledEspresso = new Caramel(basicEspresso);
    std::cout << "Cost of Carameled Decaf : " << carameledDecaf->cost() << '\n'
    << "Cost of Carameled Espresso : " << carameledEspresso->cost() << '\n';

    AddonDecorator* soyedCarameledDecaf = new Soy(carameledDecaf);
    AddonDecorator* soyedCarameledEspresso = new Soy(carameledEspresso);
    std::cout << "Cost of Soyed Carameled Decaf : " << soyedCarameledDecaf->cost() << '\n'
    << "Cost of Soyed Carameled Espresso : " << soyedCarameledEspresso->cost() << '\n';
    
    AddonDecorator* carameledCarameledDecaf = new Caramel(carameledDecaf);
    AddonDecorator* carameledCarameledEspresso = new Caramel(carameledEspresso);
    std::cout << "Cost of Carameled Carameled Decaf : " << carameledCarameledDecaf->cost() << '\n'
    << "Cost of Carameled Carameled Espresso : " << carameledCarameledEspresso->cost() << '\n';
}