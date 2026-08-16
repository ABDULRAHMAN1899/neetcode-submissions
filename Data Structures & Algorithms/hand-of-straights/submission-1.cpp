class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        unordered_map <int,int> count;
        if(n%groupSize!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int num:hand) count[num]++;
        for(int num: hand){
            if(count[num]>0){
                for(int i=num;i<num+groupSize;i++){
                    if(count[i]==0){
                        return false;
                    }
                    count[i]--;
                }
            }
        }
        return true;
    }
};
