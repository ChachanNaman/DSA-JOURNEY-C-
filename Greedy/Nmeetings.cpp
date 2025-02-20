#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class solution
{
public:
    static bool cmp(pair<int, int> a , pair<int, int>b){
        return a.second<b.second;
    }
    int maxmeets(int start[], int end[], int size)
    {
        vector<pair<int, int> >v;
        for(int i = 0 ; i<size ; i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), solution::cmp);
        int count = 1;
        int ansend =v[0].second;

        for(int i = 0; i<size ; i++){
            if(v[i].first>ansend){
                count++;
                ansend = v[i].second;
            }
        }
        return count;
    }
};
int main(){
    solution s;
    
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int size = sizeof(start) / sizeof(start[0]);

    cout << "Maximum number of meetings: " << s.maxmeets(start, end, size) << endl;
    
    return 0;
}