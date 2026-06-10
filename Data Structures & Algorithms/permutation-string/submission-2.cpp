class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(isFreqSame(freq1, freq2)) {
            return true;
        }

        for(int i = n1; i < n2; i++) {

            // add new character entering window
            freq2[s2[i] - 'a']++;

            // remove old character leaving window
            freq2[s2[i - n1] - 'a']--;

            if(isFreqSame(freq1, freq2)) {
                return true;
            }
        }

        return false;
    }
};