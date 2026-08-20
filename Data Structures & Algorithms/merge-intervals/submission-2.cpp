class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int ind=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=res[ind][1]){
                res[ind][0]=min(res[ind][0],intervals[i][0]);
                res[ind][1]=max(res[ind][1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
                ind+=1;
            }
        }
        return res;
    }
};
