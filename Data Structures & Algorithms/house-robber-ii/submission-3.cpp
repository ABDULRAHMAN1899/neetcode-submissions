class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
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
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size();
        vector<int> fv,wfv;
        for(int i=0;i<n;i++){
            if(i!=0) fv.push_back(nums[i]);
            if(i!=n-1) wfv.push_back(nums[i]);
        }
        int f=solve(fv);
        int wf=solve(wfv);
        return max(f,wf);
    }
};
