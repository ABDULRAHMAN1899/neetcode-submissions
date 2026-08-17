class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        bool third=false;
        bool first=false;
        bool second=false;
        for(auto &triplet:triplets){
            bool safe=true;
            for(int j=0;j<3;j++){
                if(triplet[j]>target[j]){
                    safe=false;
                    break;
                }
            }
            if(!safe){
                continue;
            }
            if(triplet[0]==target[0]){
                first=true;
            }
            if(triplet[1]==target[1]){
                second=true;
            }
            if(triplet[2]==target[2]){
                third=true;
            }

        }
        return first&&second&&third;
    }
};
