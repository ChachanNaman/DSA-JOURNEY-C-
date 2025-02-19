// CONSTRUCTOR
#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;
    // parametrized constructor
    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    void print()
    {
        cout <<" health : " <<this->health << endl;
        cout <<" level : "<<  this->level << endl;
        cout<<endl;
    }
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

int main()
{
    hero h1(88, 'a');
    h1.print();
    cout << " health is : " << h1.gethealth() << endl;
    cout << " level is : " << h1.level << endl;
    cout<<endl;
    hero h2(h1);
    h2.print();
    // hero *h2 = new hero;
    // h2->sethealth(90);
    // h2->setlevel('k');

    // cout<<" health is : "<<h2->gethealth()<<endl;
    // cout<<" level is : "<<h2->level<<endl;

    return 0;
}