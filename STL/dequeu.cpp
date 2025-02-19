#include <iostream>
#include <deque>
using namespace std;
int main(){

deque<int> d;
d.push_back(9);
d.push_front(6);
for(int i : d){
    cout<<i<<" ";
}cout<<endl;

cout<<"size before erase is : "<<d.size()<<endl;
d.erase(d.begin(),d.begin()+1);
cout<<"size after erase is : "<<d.size()<<endl;
d.erase(d.begin(),d.begin()+2);
cout<<"size after erase is : "<<d.size()<<endl;

    return 0;
}