class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        int hash1[26] = {0};
        int hash2[26] = {0};
        for (auto s : s1) {
            hash1[s - 'a']++;
        }
        int len = s1.size();
        int temp = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (temp < len) {
                temp++;
            } else {
                int c = 0;
                for (int j = 0; j < 26; j++) {
                    if (hash1[j] != hash2[j]) {
                        c = 1;
                        break;
                    }
                }
                if (c == 0) {
                    return true;
                }
                hash2[s2[i - len] - 'a']--;
            }
            hash2[s2[i] - 'a']++;
        }
        int c = 0;
        for (int j = 0; j < 26; j++) {
            if (hash1[j] != hash2[j]) {
                c = 1;
                break;
            }
        }
        if (c == 0) {
            return true;
        }
        return false;
    }
};
