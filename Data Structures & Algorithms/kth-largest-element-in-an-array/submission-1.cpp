class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot=nums[left];
        int i=left;
        int j=right;
        while(i<j){
            while(nums[i]<=pivot && i<=right-1){
                i++;
            }
            while(nums[j]>pivot && j>=left+1){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[left],nums[j]);
        return j;
    }
    int quickselect(vector<int>& nums, int k){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int pivotidx=partition(nums,left,right);
            if(pivotidx==k){
                return nums[pivotidx];
            }
            else if(pivotidx>k){
                right=pivotidx-1;
            }
            else{
                left=pivotidx+1;
            }
        }
        return -1;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickselect(nums,n-k);
    }
};
