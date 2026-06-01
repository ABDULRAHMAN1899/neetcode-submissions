class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<vector<int>> bucket(n+1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            bucket[it.second].push_back(it.first);
        }
        for(int i=n;i>=1;i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
        
    }
};
