class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int l=pq.top();
            pq.pop();
            int sl=pq.top();
            if(l==sl){
                pq.pop();
            }
            else {
                pq.pop();
                pq.push(l-sl);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};
