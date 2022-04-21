#pragma once

#include <iostream>
#include "IQuacking.h"

class HeavyQuacking : public IQuacking 
{
public:
    HeavyQuacking() = default;
    virtual void doQuack() override
    {
        std::cout << "Heavy Quacking...\n";
    }
};