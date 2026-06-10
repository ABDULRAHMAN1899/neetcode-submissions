class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map <char,int> count;
            int maxfreq=0;
            for(int j=i;j<n;j++){
                count[s[j]]++;
                maxfreq=max(maxfreq,count[s[j]]);
                if((j-i+1)-maxfreq<=k){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};