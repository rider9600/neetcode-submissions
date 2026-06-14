class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ind = 0;
        int m = strs[0].size();
        for (int i = 0; i < strs.size(); i++) {
            int nn = strs[i].size();
            m = min(m, nn);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < strs.size() - 1; j++) {
                {
                    if (strs[j][i] != strs[j + 1][i]) {
                        ind = i;
                        
                        string ans = strs[0].substr(0, ind);
                        return ans;
                    }
                }
            }
        }
        string ans = strs[0].substr(0,m);
        return ans;
    }
};