#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> v;


v.push_back(1);
v.push_back(7);
v.push_back(3);

for(int i:v){
    cout<<i<<" "<<endl;
}

cout<<endl;
cout<<endl;

v.push_back(9);
v.push_back(2);

v.pop_back();
v.pop_back();

for(int i:v){
    cout<<i<<" "<<endl;
}

// v.clear();

for(int i:v){
    cout<<i<<" "<<endl;
}

cout<<endl;
cout<<endl;

vector<int> v1(5,3);
for(int i : v1){
    cout<< i << " "<<endl;
}
cout<<endl;
cout<<endl;

vector<int> v2(v);
for(int i : v2){
    cout<< i << " "<<endl;
}

cout<<endl;
cout<<endl;
return 0;
}
