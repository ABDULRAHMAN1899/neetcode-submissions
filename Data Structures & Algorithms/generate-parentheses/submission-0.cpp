class Solution {
public:
    void backtrack(int open,int close,string &s,int n,vector<string>& ans){
        if(s.length()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+="(";
            backtrack(open+1,close,s,n,ans);
            s.pop_back();
        }
        if(close<n && open>close){
            s+=")";
            backtrack(open,close+1,s,n,ans);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s={};
        backtrack(0,0,s,n,ans);
        return ans;
    }
};
