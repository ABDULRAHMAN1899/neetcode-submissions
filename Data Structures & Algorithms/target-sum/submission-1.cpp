class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int nottake=solve(ind-1,target,nums,dp);
        int take=0;
        if(target>=nums[ind]){
            take=solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take+nottake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum<diff){
            return 0;
        }
        if((sum-diff)%2!=0){
            return 0;
        }
        int target=(sum-diff)/2;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solve(n-1,target,arr,dp);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(nums,target);
    }
};
