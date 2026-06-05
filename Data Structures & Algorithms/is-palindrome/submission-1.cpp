class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        } 
        while(left<=right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else{
                if(s[left]!=s[right]){
                    return false;
                }
                else{
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};
