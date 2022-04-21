#pragma once
#include <vector>
enum class STATE;
class Subject;
#include "observer.h"

enum class STATE
{
    KEY_BOARD,
    MOUSE
};

struct Position
{
    float x,y;
};

class Subject
{
public:
    Subject() = default;
    inline void attach(Observer* observer)
    {
        m_Observers.push_back(observer);
    }
    inline void dettach(Observer* observer)
    {
        for(auto itr = m_Observers.begin() ; itr != m_Observers.end() ; itr++)
        {
            if(*itr == observer)
            {
                m_Observers.erase(itr);
                break;
            }
        }
    }
    inline void notifyAllObservers()
    {
        for(Observer* observer : m_Observers)
        {
            observer->update(stateAffected);
        }
    }
    inline STATE getState() const
    {
        return stateAffected;
    }
    inline void setKey(char key)
    {
        stateAffected = STATE::KEY_BOARD;
        keyPressed = key;
        notifyAllObservers();
    }
    inline char getKey()
    {
        return keyPressed;
    }
    inline void setMousePos(int x,int y)
    {
        stateAffected = STATE::MOUSE;
        mousePosition.x = x;
        mousePosition.y = y;
        notifyAllObservers();
    }
    Position getMousePos()
    {
        return mousePosition;
    }
private:
    std::vector<Observer*> m_Observers;
    STATE stateAffected;
    char keyPressed;
    Position mousePosition;
};