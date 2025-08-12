class Solution {
public:

    int solveSO(vector<int>& obstacles){
        int n = obstacles.size()-1;

        //making 2 array
        vector<int>curr(4 , 0);
        vector<int>next(4 , 0);

        //Base Case initialse in dp (last nth meet is return 0)
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        
        for(int pos = n-1; pos>=0 ; pos--){
            for(int currlane = 1 ; currlane<=3 ; currlane++){
                if(obstacles[pos+1] != currlane){
                curr[currlane] = next[currlane];
               }
            else{
            int ans = 1e9;
            for(int i = 1 ; i<=3 ; i++){
                if(currlane != i && obstacles[pos] != i){
                    //means current lane should not be continued for jump
                    //and obstacle shouldn't be there at that lane
                    ans = min(ans , 1+next[i]);
                }
            }
            curr[currlane] = ans;
            }
            }
            next = curr;
        }
        return min(next[2] ,min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {

        return solveSO(obstacles);
    }
};