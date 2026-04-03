#include <iostream>
#define Critical " Duck Duck DUCK!! "
#define DamageExposed " NICE DATA "
#define Warn " DO YOUR HOMEWORK "
#define OKI " GIT GUD "
#define Perfect " GARANA "

struct Error
{

    void throwShit(std::string source, std::string lvl, std::string msg)
    {
        std::cout << source << " $ " << lvl << msg << "\n";
    }

}err;
