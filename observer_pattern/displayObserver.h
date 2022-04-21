#pragma once
#include <iostream>
#include "subject.h"
#include "observer.h"

class DisplayObserver : public Observer
{
public :
    DisplayObserver(Subject* subject)
   {
        theSubject = subject;
        theSubject->attach(this);
    }
    virtual void update(STATE state) override
    {
        switch (state)
        {
        case STATE::KEY_BOARD:
            std::cout << "Display Update for KeyPress: " << theSubject->getKey() << '\n';
            break;
        case STATE::MOUSE:
            std::cout << "Display Update for Mouse Move:" 
            << " x : " << theSubject->getMousePos().x  
            << " y : " << theSubject->getMousePos().y << '\n';
            break;
        default:
            break;
        }
    }
};
