class Solution {
public:
    void backtrack(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        backtrack(ind+1,nums,ans,ds);
        ds.pop_back();
        int idx=ind+1;
        while(idx<nums.size()&&nums[idx]==nums[idx-1]){
            idx++;
        }
        backtrack(idx,nums,ans,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,ans,ds);
        return ans;
    }
};
