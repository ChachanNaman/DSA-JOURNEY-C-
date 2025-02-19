#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s;

    s.push(9);
    s.push(2);
    s.push(3);
    

    s.pop();
    s.pop();
    s.pop();

    // cout<<"Top element is : "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty ! "<<endl;
    }
    else{
        cout<<"Stack is not empty ! "<<endl;
    }
    return 0;
}