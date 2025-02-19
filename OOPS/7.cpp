// POLYMORPHISM 
// FUNCTION OVERLOADING 
#include <iostream>
using namespace std;

// class naman{
//     public: 
// void hello(){
//     cout<< " hello naman ! "<<endl;
//     cout<<endl;
// }
// int hello(string name , int n){
//     cout<< " hello naman ! "<<endl;
//     cout<<endl;
//     return 1;
// }
// void hello(string name){
//     cout<< " hello naman ! "<<name<<endl;
// }
// };

// int main(){
//     naman n1;
//     n1.hello();
//     return 0;
// }

// RUNTIME POLYMORPHISM 
class animal{
public :
void speak(){
    cout << " speaking ! "<<endl;
    cout<<endl;
}
};
class dog : public animal {
    public:
    void speak(){
        cout<<" barking ! "<<endl;
        cout<<endl;
    }
};

int main(){
    animal a1;
    a1.speak();
    dog d1;
    d1.speak();
    return 0;
}