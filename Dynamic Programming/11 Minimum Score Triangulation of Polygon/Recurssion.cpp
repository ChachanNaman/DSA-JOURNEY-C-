class Solution {
public:
    //i have to return minimum score by multiplying edges of diff triangles formed
    int solve(vector<int>& values , int i , int j){
        if(i+1==j){ //Base Case
            //means only two vertex is there then i+1=j
            return 0;
        }
        
        int ans = INT_MAX;
        //for loop for k can be anywhere in polygon , soo k to traverse all
        for(int k=i+1 ; k<j ; k++){//where k starts from i+1(start) and should  be in j(end point)
            ans = min(ans , values[i]*values[j]*values[k]+solve(values ,i ,k)+solve(values ,k, j));
            //i to k and k to j -> k in place of j firstly , k in place of i secondly
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        return solve(values , 0 , n-1);

    }
};