class Solution {
public:

    int solve(vector<int>& obstacles, int currlane , int pos){
        int n = obstacles.size()-1; //last position
        if(pos == n){//Base Case(if start = end then no jump)
            return 0;
        }

        if(obstacles[pos+1] != currlane){//obstacles[pos+1] gives lane where obs is like obstacles[1] = 3 means at position 1 obstacle is in 3 lane
            return solve(obstacles , currlane , pos+1);//just move frog in curr lane , means no obstacle there in current path
        }
        else{//obstacle there in current path
            //i have to get minimum jump also like suppose if both up and down jump can happen soo i have to get minimum out of it soo using minimum
            int ans = INT_MAX;
            for(int i = 1 ; i<=3 ; i++){
                if(currlane != i && obstacles[pos] != i){
                    //means current lane should not be continued for jump
                    //and obstacle shouldn't be there at that lane
                    ans = min(ans , 1+solve(obstacles , i , pos));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        //curr lane in start is always 2 from 1,2,3
        //and position is 0 as frog starting from start
        return solve(obstacles , 2, 0);
    }
};