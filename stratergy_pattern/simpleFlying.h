#pragma once
#include <iostream>
#include "IFlying.h"

class SimpleFlying : public IFlying
{
public :
    SimpleFlying() = default;
    virtual void doFly() override
    {
        std::cout << "Simple Flying...\n";
    }
};