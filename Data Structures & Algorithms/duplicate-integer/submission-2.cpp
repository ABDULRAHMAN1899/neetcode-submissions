class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool flag=false;
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]>1){
                flag=true;
            }
        }
        return flag;
    }
};