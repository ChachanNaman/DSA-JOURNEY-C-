#include <iostream>
using namespace std;

class student
{
protected:
    int weight;
    int height;

private:
    int age;

public:
    int getage()
    {
        return this->age;
    }
    void setweight(int w)
    {
        this->weight = w;
    }

};
class student1 : private student
{
public:
    string colour;
    void hello()
    {
        cout << " hello guys ! " << endl;
        cout << endl;
    }
        void setheight(int h)
    {
        this->height = h;
    }
    int getheight()
    {
        return this->height;
    }
};
int main()
{
    student1 naman;
    naman.setheight(5);
    cout << "height is : " << naman.getheight() << endl;

    return 0;
}