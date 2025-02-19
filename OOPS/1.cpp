// if the class is empty then space allocated to it is 1 BYTE
//  private ko sirf class ke andar access kar sakte hai
#include <iostream>
using namespace std;
class hero
{
public:
    int health;

private:
    char level;
    public : 

    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
    void sethealth(int h)
    {
        health = h;
    }
    void setlevel(char l)
    {
        level = l;
    }
};

int main()
{

    hero h1;
    // cout<<"size of empty class is : "<< sizeof(h1)<<endl;
    h1.health = 98;
    // h1.level = 'a';
    h1.setlevel('b');
    cout << " health is : " << h1.health << endl;
    cout << " level is : " << h1.getlevel() << endl;
    return 0;
}
