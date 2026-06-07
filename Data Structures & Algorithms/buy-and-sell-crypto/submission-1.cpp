class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprof=INT_MIN;
        int minprice=INT_MAX;
        for(int i=0;i<n;i++){
            int current=prices[i];
            minprice=min(minprice,current);
            int profit=current-minprice;
            if(profit>maxprof){
                maxprof=profit;
            }
        }
        return maxprof;
    }
};