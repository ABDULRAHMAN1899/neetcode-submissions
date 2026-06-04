class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        int lastsmallest=INT_MIN;
        int cnt=1;
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastsmallest){
                cnt++;
                lastsmallest=nums[i];
            }
            else if(nums[i]!=lastsmallest){
                cnt=1;
                lastsmallest=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};
