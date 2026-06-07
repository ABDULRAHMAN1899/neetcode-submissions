class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprof=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prof=prices[j]-prices[i];
                maxprof=max(maxprof,prof);
            }
            
        }
        if(maxprof==-1){
            return 0;
        }
        return maxprof;
    }
};