class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n<3){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int rob=nums[i]+prev2;
            int drob=prev;
            int curri=max(rob,drob);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
    }
};
