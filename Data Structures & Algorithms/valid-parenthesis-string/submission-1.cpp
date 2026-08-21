class Solution {
public:
    bool solve(int ind,string & s,int cnt, vector<vector<int>>& dp){
        if(cnt<0){
            return false;
        }
        if(ind==s.length()){
            if(cnt==0){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }
        if(s[ind]=='('){
            return dp[ind][cnt]=solve(ind+1,s,cnt+1,dp);
        }
        if(s[ind]==')'){
            return dp[ind][cnt]=solve(ind+1,s,cnt-1,dp);
        }
        return dp[ind][cnt]=solve(ind+1,s,cnt+1,dp) || 
        solve(ind+1,s,cnt-1,dp) || solve(ind+1,s,cnt,dp);
    }
    bool checkValidString(string s) {
        int cnt=0;
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,s,cnt,dp);
    }
};
