class Solution {
public:
    int solve(vector<int>& nums,int idx,vector<int>& dp){
        if(idx<0){
            return 0;
        }
        if(idx==0){
            return nums[0];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int rob=solve(nums,idx-2,dp)+nums[idx];
        int drob=solve(nums,idx-1,dp);
        return dp[idx]= max(rob,drob);
    }
    int rob(vector<int>& nums) {
        int idx=nums.size()-1;
        vector<int> dp(nums.size(),-1);
        return solve(nums,idx,dp);
        
    }
};
