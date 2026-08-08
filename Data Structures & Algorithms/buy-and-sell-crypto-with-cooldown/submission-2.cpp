class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        int profit=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int canbuy=0;canbuy<2;canbuy++){
                if(canbuy){
                profit=max((-prices[ind]+dp[ind+1][0]),
                dp[ind+1][1]);
                }
                else{
                    profit=max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]);
                }
                dp[ind][canbuy]=profit;
            }
        }
        return dp[0][1];
    }
};
