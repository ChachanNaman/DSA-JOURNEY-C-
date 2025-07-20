#include <iostream>
using namespace std;

void reached(int src , int dest){

    cout <<"source : "<<src<<" destination : "<<dest<<endl;
    if(src == dest){
        cout<<" ghar aagya ! "<<endl;
        return;
    }
    src++;
    reached(src , dest);

}

int main(){


    int src = 1;
    int dest = 10;

    reached(src, dest);
    return 0;
}