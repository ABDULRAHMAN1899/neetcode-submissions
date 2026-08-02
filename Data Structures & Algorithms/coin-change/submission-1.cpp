class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins){
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
        int np=solve(ind-1,amount,coins);
        int p=1e9;
        if(amount>=coins[ind]){
            p=1+solve(ind,amount-coins[ind],coins);
        }
        return min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans= solve(n-1,amount,coins);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
