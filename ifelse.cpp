    #include <iostream>
    using namespace std;

    int main()
    {
        int a;
        char n ;
        // do
        // {
        // cout << "enter the digit : " << endl;
        // cin >> a;

        // if (a > 0)
        // {
        //     cout << "a is positive " << endl;
        // }
        // else if (a == 0)
        // {
        //     cout << "a is 0 " << endl;
        // }
        // else
        // {
        //     cout << "a is negative" << endl;
        // }
        // cout<<"do you want to check for more(y/n)"<<endl;
        // cin>>n;
        // } while (n=='y');

        //HOMEWORK:
        // cout<<"enter the data you want to check "<<endl;
        // cin>>n;
        // if(n>='a' && n<='z'){
        //     cout<<"character are small"<<endl;
        // }
        // else if(n>='A'&&n<='Z'){
        //     cout<<"character are upper case"<<endl;
        // }
        // else {
        //     cout<<"character is numeric"<<endl;
        // }
        // cout<<"enter the number : "<<endl;
        // cin>>a;
        // int sum = 0 ;
        // int i = 2;
        // while(i<=a){
        // if(i%2==0){
        //      sum = sum + i ;
        // }
        //     i= i +2;
        // }
        // cout<<sum<<endl;
        // cout<<"enter the number "<<endl;
        // cin>>a;
        // int i = 1;
        // while (i<= a)
        // {
        //     int j= 1;
        //      while (j<= a)
        //      {
        //         cout<<j;    //for straight order
        //         // cout<<a-j+1;  //for reverse   order
        //         j++;
        //      }
        //      cout<<endl;
           
        //      i++;
             
        // }
        // cout<<"enter the number : "<<endl;
        // cin>>a;
        // int i=1;
        // int count = 1;
        // while (i<=a)
        // {
        //     int j = 1;
        //     while(j<= a){
        //         cout<<count<<" ";
        //         count++;
        //         j++;
        //     }
        //     cout<<endl;
        //     i++;
        // }
        //STAR :
        // cout<<"enter the number "<<endl;
        // cin>>a;
        // int i = 1;
        // while (i<= a)
        // {int j = 1;  
        //     while(j<= i){
        //         cout<<"*";
        //         j++;
        //     }
        //     cout<<endl;
        //     i++;
        // }
// TO START TRIANGLE FROM INITIAL NUMBER OF THE ROW
        cout<<"enter the number : "<<endl;
        cin>>a;
        int i=1;
        
        while (i<=a)
        {
            int j = 1;
            int count = i;
            while(j<= i){
                cout<<count<<" ";
                count++;
                j++;
            }
            cout<<endl;
            i++;
        }
        
        return 0;
    }
