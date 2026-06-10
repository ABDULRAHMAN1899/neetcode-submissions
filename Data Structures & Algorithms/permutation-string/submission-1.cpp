class Solution {
public:
    bool isfreqsame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        int freq[26]={0};
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
        }
        int wndsz=n1;
        for(int i=0;i<n2;i++){
            int widx=0,idx=i;
            int wfreq[26]={0};
            while(widx<wndsz && idx<n2){
                wfreq[s2[idx]-'a']++;
                widx++;
                idx++;
            }
            if(isfreqsame(freq,wfreq)){
                return true;
            }
        }
        return false;
    }
};
