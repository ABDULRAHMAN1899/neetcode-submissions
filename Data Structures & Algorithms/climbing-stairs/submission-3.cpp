class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        int curri=0;
        for(int i=2;i<=n;i++){
            curri=prev2+prev;
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};
