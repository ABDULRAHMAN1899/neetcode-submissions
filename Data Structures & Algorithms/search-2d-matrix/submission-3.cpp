class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=m*n-1;
        bool flag=false;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[mid/n][mid%n]==target){
                flag=true;
                return flag;
            }
            else if(matrix[mid/n][mid%n]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return flag;
    }
};
