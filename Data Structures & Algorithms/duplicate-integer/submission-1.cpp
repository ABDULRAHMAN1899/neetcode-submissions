class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool flag=false;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                flag=true;
            }
        }
        }
        return flag;
    }
};