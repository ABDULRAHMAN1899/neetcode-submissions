class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        int n3=ans.size();
        if(n3%2 !=0){
            return ans[n3/2];
        }
        else{
            double res=(ans[n3/2]+ans[(n3/2)-1])/(double)2;
            return res;

        }
        return -1;
    }
};
