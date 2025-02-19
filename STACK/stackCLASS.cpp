#include <iostream>
using namespace std;
class Stack{
    public :
    int *arr;
    int size;
    int top;
    Stack(int size){
        this ->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(top == size-1){
            cout<<"Stack overflow ! "<<endl;
        }
        else{
            top++;
            arr[top] = element;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflor ! "<<endl;
           
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top>=0 ){
            return arr[top];
        }
        else{
            cout<<"Stack is empty ! "<<endl;
            return -1;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack st(5);
    st.push(33);
    st.push(22);
    st.push(11);

    cout<<"top element is : "<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    if(st.empty()){
            cout<<"stack is empty ! "<<endl;
    }
    else{
        cout<<"stack is not empty ! "<<endl;
    }

    return 0;
}