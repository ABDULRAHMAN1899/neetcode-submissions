class Solution {
public:
    int solve(int ind,int target,vector<int>& nums){
        if(ind==0){
            if(target==0 && nums[0]==0){
                return 2;
            }
            if(nums[0]+target==0 || nums[0]-target==0){
                return 1;
            }
            return 0;
        }
        int psub=solve(ind-1,target+nums[ind],nums);
        int padd=solve(ind-1,target-nums[ind],nums);
        return padd+psub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,target,nums);
    }
};
