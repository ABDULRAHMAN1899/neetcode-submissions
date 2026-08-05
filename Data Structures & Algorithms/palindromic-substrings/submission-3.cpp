class Solution {
public:
    int countSubstrings(string s) {
        int left=0,right=0;
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            left=right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                cnt++;
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                cnt++;
                left--;
                right++;
            }
        }
        return cnt;

    }
};
