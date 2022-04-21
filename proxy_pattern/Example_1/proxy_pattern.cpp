#include <iostream>
#include <string>

class Image
{
public :
    Image() = default;
    virtual void display() = 0;
};

class RealImage : public Image 
{
public : 
    RealImage(const std::string& src)
        : file_name{src}
    {
        loadFromDisk();
        display();
    }
    virtual void display() override
    {
        std::cout << "Displaying Image : " << file_name << '\n';
    }
    void loadFromDisk()
    {
        std::cout << "Loading Image from : " << file_name << '\n';
    }
private :
    std::string file_name;
};

class ProxyImage : public Image
{
public :
    ProxyImage(const std::string& src)
        : file_name{src}
    {

    }
    virtual void display() override
    {
        if (realImage == nullptr)
        {
            realImage = new RealImage(file_name);
        }
        else
        {
            realImage->display();
        }
    }
private :
    RealImage* realImage = nullptr;
    std::string file_name;
};

int main()
{
    ProxyImage* proxyImage = new ProxyImage("Hello-kitty");
    proxyImage->display(); // loading + displaying

    proxyImage->display(); // displaying
}