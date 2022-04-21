#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

int main()
{
    std::set <std::string> asd,lsd;
    asd.insert({"hello","llo"});
    lsd = asd;
    for (std::set<std::string>::iterator itr = asd.begin() ; itr != asd.end() ; itr++)
    {
        std::set<std::string>::iterator j = itr;
        for (std::advance(j,1) ; j != asd.end() ; j++)
        {
           // std::cout << *itr << ' ' <<  *j ; 
            if ((*j).find_last_of(*itr,(*j).size()))
            {
               // lsd.erase(j);
               lsd.erase(*j);
            }
        }
    }
    std::cout << lsd.size();
    return 0;
}