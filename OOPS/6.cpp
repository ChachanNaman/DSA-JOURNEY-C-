// INHERITANCE AND AMBUIGUITY 

#include <iostream>
using namespace std;
// MULTIPLE INHERITANCE
// class animal{
//     public :
//     void barking(){
//         cout<<" barking ! "<<endl;
//         cout<<endl;
//     }
// };
// class human{
//     public:
//     void speaking(){
//         cout<<" speaking ! "<<endl;
//         cout<<endl;
//     }
// };
// class hybrid : public animal , public human{

// };
// int main(){
//     hybrid h;
//     h.barking();
//     h.speaking();
//     return 0;
// }

// HIERARICHAL INHERITANCE
class a
{
public:
    void func1()
    {
        cout << " inside func 1 " << endl;
        cout << endl;
    }
};
class b : public a
{
public:
    void func1()
    {
        cout << " inside func 2 " << endl;
        cout << endl;
    }
};
class c : public a
{
public:
    void func3()
    {
        cout << " inside func 3 " << endl;
        cout << endl;
    }
};

int main()
{
    a a1;
    a1.func1();
    b b1;
    b1.a::func1();
    b1.b::func1();
    c c1;
    c1.a::func1();

    c1.func3();
}