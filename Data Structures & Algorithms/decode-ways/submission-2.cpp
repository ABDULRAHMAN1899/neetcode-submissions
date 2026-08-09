class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+3,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--){
            if(s[ind] == '0'){
                dp[ind] = 0;
                continue;
            }
            int one=dp[ind+1];
            int num=0;
            int two=0;
            if(ind+1<s.length()){
                num = (s[ind] - '0') * 10 + (s[ind+1] - '0');
            }
            if(num>=10 && num<=26){
                two=dp[ind+2];
            }
            dp[ind]=one+two;
        }

        return dp[0];
    }
};
