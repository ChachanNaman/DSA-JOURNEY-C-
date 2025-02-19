// CONSTRUCTOR
#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;
    // static keyword
    static int time;
    // parametrized constructor
    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    // static function
    static int random()
    {
        return time;
    }
    void print()
    {
        cout << " health : " << this->health << endl;
        cout << " level : " << this->level << endl;
        cout << endl;
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
// static keyword
int hero ::time = 10;
int main()
{

    hero h1(88, 'a');
    h1.print();
    cout << " health is : " << h1.gethealth() << endl;
    cout << " level is : " << h1.level << endl;
    cout << " time to complete : " << hero::time << endl; // static keyword call
    cout << "static function called : " << hero::random() << endl;
    cout << endl;
    hero h2(h1);
    h2.print();
    // hero *h2 = new hero;
    // h2->sethealth(90);
    // h2->setlevel('k');

    // cout<<" health is : "<<h2->gethealth()<<endl;
    // cout<<" level is : "<<h2->level<<endl;

    return 0;
}