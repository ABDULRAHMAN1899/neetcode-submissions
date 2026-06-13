class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int count=0;
            bool found=false;
            for(int j=i+1;j<n;j++){
                count++;
                if(temperatures[i]<temperatures[j]){
                    ans.push_back(count);
                    found=true;
                    break;
                }
            }
            if(!found){
                ans.push_back(0);
            }
        }
        return ans;
    }
};
