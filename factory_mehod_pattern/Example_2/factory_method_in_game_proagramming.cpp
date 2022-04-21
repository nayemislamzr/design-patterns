#include <iostream>

class Object
{
public :
    Object() = default;
    virtual void create() = 0;
};

class Tree : public Object
{
public :
    Tree() = default;
    Tree(int size)
        : _treeSize{size}
    {

    }
    virtual void create() = 0;
protected :
    int _treeSize;
};

class DeciduosTree : public Tree
{
public :
    DeciduosTree(int size)
       : Tree{size}
    {

    }
    virtual void create() override
    {
        std::cout << "Deciduos Tree Created of size : " << _treeSize << "\n";
    }
};

class EverGreenTree : public Tree
{
public :
    EverGreenTree(int size)
       : Tree{size}
    {

    }
    virtual void create() override
    {
        std::cout << "EverGreen Tree Created of size : " << _treeSize << "\n";
    }
};

class Stone : public Object
{
public :
    Stone() = default;
    Stone(int size)
        : stoneSize{size}
    {

    }
    virtual void create() = 0;
protected :
    int stoneSize;
};

class SedimenticStone : public Stone
{
public :
    SedimenticStone(int size)
        : Stone{size}
    {

    }
    virtual void create() override
    {
        std::cout << "Sedimentic Stone created of size : " << stoneSize << '\n';
    }
};

class ArtificialStone : public Stone
{
public :
    ArtificialStone(int size)
        : Stone{size}
    {

    }
    virtual void create() override
    {
        std::cout << "Artificial Stone created of size : " << stoneSize << '\n';
    }
};

class ObjectFactory
{
public :
    ObjectFactory() = default;
    void createObject(Object* objectType)
    {
        chosenObject = objectType;
        create();
    }
    
private :
    Object* chosenObject;
    void create()
    {
        chosenObject->create();
    }
};

int main()
{
    ObjectFactory* factory = new ObjectFactory();
    factory->createObject(new EverGreenTree(12));
    factory->createObject(new ArtificialStone(23));
    factory->createObject(new DeciduosTree(45));
    factory->createObject(new SedimenticStone(65));
}