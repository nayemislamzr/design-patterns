#pragma once
#include <iostream>
#include "IQuacking.h"

class simpleQuacking : public IQuacking
{
public:
    simpleQuacking() = default;
    virtual void doQuack() override
    {
        std::cout << "Simple Quacking...\n";
    }
};