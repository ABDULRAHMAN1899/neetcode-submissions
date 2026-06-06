class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int left=0;
        int right=n-1;
        int maxarea=-1;
        while(left<=right){
            int sh=min(heights[left],heights[right]);
            int xdiff=right-left;
            int area=xdiff*sh;
            maxarea=max(maxarea,area);
            if(sh==heights[left]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxarea;
        
    }
};
