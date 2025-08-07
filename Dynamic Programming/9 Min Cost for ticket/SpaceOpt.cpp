class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;

        queue<pair<int,int>>month;
        queue<pair<int,int>>week;
        //Two queues to store:
        //for month pass: (day, cost till now + cost of 30-day pass)
        //for week pass: (day, cost till now + cost of 7-day pass)


        for(int day : days){
        //step-1: remove expired days from queue
        while(!month.empty() && month.front().first+30<=day){
            month.pop();
        }till 
        //like if i am on day 35 and pass was of 30 days then it should be expired 
        //soo traversing 
        while(!week.empty() && week.front().first+7<=day){
            week.pop();
        }

        //step-2: add cost for current day
        week.push(make_pair(day , ans+costs[1]));
        month.push(make_pair(day , ans+costs[2]));

        //step-3: update the ans
        ans = min(ans+costs[0], min(month.front().second, week.front().second));
        }//day for loop
        return ans;
    }
};