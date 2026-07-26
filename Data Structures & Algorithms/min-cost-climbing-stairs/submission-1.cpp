class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int idx=cost.size();
        int prev2=0;
        int prev=0;
        for(int i=2;i<=idx;i++){
            int fs=prev+cost[i-1];
            int ss=INT_MAX;
            if(i>1){
                ss=prev2+cost[i-2];
            }
            int curri=min(fs,ss);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};
