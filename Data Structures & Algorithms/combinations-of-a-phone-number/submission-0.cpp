class Solution {
public:
vector<string> res;
vector<string> digitToChar =
        {"","","abc","def","ghi","jkl","mno","pqrs", "tuv", "wxyz"};

    void solve(int i,string curstr,string & digits){
        if(curstr.length()==digits.length()){
            res.push_back(curstr);
            return;
        }
        string chars=digitToChar[digits[i]-'0'];
        for(char c : chars){
            solve(i+1,curstr+c,digits);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return res;
        }
        solve(0,"",digits);
        return res;
    }
};
