class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string newstr="";
        for(char c:s){
            if(isalnum(c)){
                newstr+=tolower(c);
            }
        }
        return newstr==string(newstr.rbegin(),newstr.rend());

    }
};
