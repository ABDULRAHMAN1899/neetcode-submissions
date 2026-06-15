class Solution {
public:
    bool eating(vector<int>& piles,int mid,int h){
        int n=piles.size();
        double count=0;
        for(int i=0;i<n;i++){
            count+=ceil((double)piles[i]/(double)mid);
        }
        if(count<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int l=1;
        int r=maxi;
        while(l<=r){
            int mid=(l+r)/2;
            if(eating(piles,mid,h)==true){
                r=mid-1;
            }
            else if (eating(piles,mid,h)==false){
                l=mid+1;
            }
            
        }
        return l;
    }
};
