#include <iostream>

/**
 * Basic Structure
 **/

class Singleton
{
public:
    Singleton(const Singleton&) = delete; // deleting copy constructor
    static Singleton& Get() 
    {
        static Singleton s_Instance; // creating a single instance
        return s_Instance; // returning the single instance
    }
    static float area(){return Get().areaImpl();} // a wrap for Get() withoutcalling Get() in declaration 
    static void setRaduis(float r){Get().radius = r;}
private:
    Singleton() = default; // private default constructor
    float radius;
    static constexpr float pi = 3.1416;
    static float areaImpl() // a static function using non-static data
    {
        return Get().radius*2*pi;
    }
};

int main()
{
    // First way of declaring singleton
    // Singleton::Get().setRaduis(12.0f);
    // std::cout  <<   Singleton::Get().area();

    // Second way of declaring singleton
    Singleton& f = Singleton::Get();
    f.setRaduis(12.0f);
    std::cout << f.area();
    return 0;
}

/**
 * Example : A stack based music manager
 **/
/*
#include <vector>
#include <string>

class MusicManager
{
public:
    MusicManager(const MusicManager&) = delete;
    static MusicManager& Get()
    {
        static MusicManager s_Instance;
        return s_Instance;
    }
    static void add(const std::string& song)
    {
        MusicManager& instance = Get();
        instance.songs.emplace_back(std::move(song));
        ++(instance.songCount);
        std::cout << "Added : " << song << '\n';
    }
    static void play()
    {
        // do some work
        std::cout << "Playing : " <<  Get().songs.back() << '\n';
    }
    static void remove()
    {
        std::string toRemove = Get().songs.back();
        Get().songs.pop_back();
        std::cout << "Removed : " << toRemove << '\n'; 
    }
    static totalSong()
    {
        return Get().songCount;
    }
private:
    MusicManager() = default;
    std::vector<std::string> songs;
    int songCount = 0;
};

int main()
{
    MusicManager& music = MusicManager::Get();
    music.add("manike mage hithe");
    music.add("despacito");
    music.add("ranj de basanti");
    music.play();
    music.remove();
    music.add("Waka waka");
    music.remove();
    music.remove();
    music.play();
    music.remove();
}
*/