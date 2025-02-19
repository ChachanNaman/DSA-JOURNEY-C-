#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;
    void sethealth(int h)
    {
        health = h;
    }
    void setlevel(char l)
    {
        level = l;
    }
    int gethealth()
    {
        return health;
    }
    int getlevel()
    {
        return level;
    }
};

int main(){
    hero h1;
    h1.sethealth(34);
    h1.setlevel('f');
    cout<<" health is : "<<h1.gethealth()<<endl;
    cout<<" level is : "<<h1.level<<endl;

    hero *h2 = new hero;
    h2->sethealth(90);
    h2->setlevel('k');

    cout<<" health is : "<<h2->gethealth()<<endl;
    cout<<" level is : "<<h2->level<<endl;

    return 0;
}