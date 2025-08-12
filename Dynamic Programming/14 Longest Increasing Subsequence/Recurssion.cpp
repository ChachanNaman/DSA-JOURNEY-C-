class Solution {
  public:
    int solve(int n ,vector<int>& arr, int curr , int prev ){
        if(curr == n){//Base Case
            return 0;
        }
        
        //include
        int take =0;
        if(prev == -1 || arr[curr]>arr[prev]){
            take = 1+solve(n , arr , curr+1, curr);
        }
        
        //exlude
        int nottake = 0 + solve(n , arr, curr+1, prev);
        
        return max(take , nottake);

    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        return solve(n , arr , 0, -1);
    }
};