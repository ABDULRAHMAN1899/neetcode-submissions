class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            set<int> hashset;
            for(int j=i+1;j<n;j++){
                int third=-(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                    vector<int> temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                else{
                    hashset.insert(nums[j]);
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
