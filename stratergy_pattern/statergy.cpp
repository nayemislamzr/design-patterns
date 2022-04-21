#include <iostream>
#include "IQuacking.h"
#include "IFlying.h"
#include "simpleQuacking.h"
#include "simpleFlying.h"
#include "heavyQuacking.h"
#include "jetFlying.h"

class Duck
{
public :
    Duck() = default;
    ~Duck() = default;
    void setQuack(IQuacking* qucking)
    {
        quckingBehave = qucking;
    }
    void doQuack()
    {
        quckingBehave->doQuack();
    }
    void setFly(IFlying* flying)
    {
        flyingBehave = flying;      
    }
    void doFly()
    {
        flyingBehave->doFly();
    }
private:
    IQuacking* quckingBehave;
    IFlying* flyingBehave;
};

int main()
{
    Duck wildDuck;
    wildDuck.setQuack(new HeavyQuacking());
    wildDuck.setFly(new jetFlying());
    wildDuck.doQuack();
    wildDuck.doFly();

    Duck cityDuck;
    cityDuck.setQuack(new simpleQuacking());
    cityDuck.setFly(new SimpleFlying());
    cityDuck.doQuack();
    cityDuck.doFly();
}