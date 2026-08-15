class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int currgas = 0;
        int start = 0;
        int gsum = 0;
        int csum = 0;

        for(int i = 0; i < n; i++){
            gsum += gas[i];
            csum += cost[i];
        }

        if(csum > gsum){
            return -1;
        }

        for(int i = 0; i < n; i++){
            currgas += gas[i] - cost[i];
            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }

        return start;
    }
};