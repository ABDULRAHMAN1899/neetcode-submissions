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
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>fv;
        vector<int> wfv;
        for(int i=0;i<idx;i++){
            fv.push_back(nums[i]);
        }
        for(int i=1;i<=idx;i++){
            wfv.push_back(nums[i]);
        }
        vector<int> dp1(nums.size()-1,-1);
        vector<int> dp2(nums.size()-1,-1);

        int f=solve(fv,idx-1,dp1);
        int wf=solve(wfv,idx-1,dp2);
        return max(f,wf);
    }
};
