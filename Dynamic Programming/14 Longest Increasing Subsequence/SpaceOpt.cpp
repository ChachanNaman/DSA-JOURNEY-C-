class Solution {
  public:
 
    int solveSO(int n ,vector<int>& arr){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1, 0);
         for(int curr = n-1 ; curr>=0 ; curr--){
             for(int prev = curr-1 ; prev >= -1; prev--){
                 
                 int take = 0;
                 if(prev == -1 || arr[curr]>arr[prev]){
                     take = 1 + nextRow[curr+1];
                 }
                 
                 //exclude
                 int nottake = 0 + nextRow[prev+1];//did +1 here in prev to save from -1
                 currRow[prev+1] = max(take , nottake);                 
             }
             nextRow = currRow;
         }
         return nextRow[0];
    }//Time Complexity: O(n^2)
    //Space Complexity: O(n)
    //but didnt match Time Complecity of O(n log n). soo new solution including binary search
    
    
    
    
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();

        return solveSO(n ,arr);
    }
};
