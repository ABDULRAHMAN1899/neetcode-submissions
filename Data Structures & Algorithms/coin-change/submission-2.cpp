class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins, vector<vector<int>>& dp){
        if (amount==0){
            return 0;
        }
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int np=solve(ind-1,amount,coins,dp);
        int p=1e9;
        if(amount>=coins[ind]){
            p=1+solve(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
