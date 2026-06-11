class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        int minlen = INT_MAX;
        int sidx = -1;

        for(int i = 0; i < n1; i++) {

            int hash[256] = {0};

            for(char c : t) {
                hash[c]++;
            }

            int cnt = 0;

            for(int j = i; j < n1; j++) {

                if(hash[s[j]] > 0) {
                    cnt++;
                }

                hash[s[j]]--;

                if(cnt == n2) {

                    if(j - i + 1 < minlen) {
                        minlen = j - i + 1;
                        sidx = i;
                    }

                    break;
                }
            }
        }

        if(sidx == -1) {
            return "";
        }

        return s.substr(sidx, minlen);
    }
};