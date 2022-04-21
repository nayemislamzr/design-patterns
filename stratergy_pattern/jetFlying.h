#pragma once

#include <iostream>
#include "IFlying.h"

class jetFlying : public IFlying
{
public :
    jetFlying() = default;
    virtual void doFly() override
    {
        std::cout << "Jet Flying...\n";
    }
};