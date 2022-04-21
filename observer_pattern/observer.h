#pragma once
#include "subject.h"

class Observer
{
public:
    Observer() = default;
    virtual void update(STATE) = 0;
protected:
    Subject* theSubject;
};