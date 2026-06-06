class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sh=min(heights[i],heights[j]);
                int xdiff=j-i;
                int area=xdiff*sh;
                maxarea=max(maxarea,area);
            }

        }
        return maxarea;
    }
};
