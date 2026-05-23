class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mpp1;
        unordered_map <char,int> mpp2;
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            mpp1[s[i]]++;
        }
        for(int j=0;j<n2;j++){
            mpp2[t[j]]++;
        }
        for(int i=0;i<n1;i++){
            if(mpp1[s[i]]!=mpp2[s[i]]){
                return false;
            }
        }
        return true;

    }
};
