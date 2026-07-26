class Solution {
public:
    int solve(int idx,vector<int>& cost,vector<int>& dp){
        if(idx==0){
            return 0;
        }
        if(idx==1){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int left=solve(idx-1,cost,dp)+cost[idx-1];
        int right=INT_MAX;
        if(idx>1){
            right=solve(idx-2,cost,dp)+cost[idx-2];
        }
        return dp[idx]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int idx=cost.size();
        vector<int> dp(idx+1,-1);
        return solve(idx,cost,dp);  
    }
};
