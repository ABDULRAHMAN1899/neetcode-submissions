class Solution {
public:
    void backtrack(int ind,vector<int>& nums,set<vector<int>>& ans,vector<int>& ds){
        if(ind==nums.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        backtrack(ind+1,nums,ans,ds);
        ds.pop_back();
        backtrack(ind+1,nums,ans,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,ans,ds);
        for(auto it: ans){
            res.push_back(it);
        }
        return res;
    }
};
