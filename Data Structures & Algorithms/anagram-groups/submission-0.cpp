class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int ind = 0;
        map<vector<int>,int> mp;
        vector<vector<string>> ans;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            vector<int> chari(26);
            for (int j = 0; j < strs[i].size(); j++) {
                chari[strs[i][j] - 'a']++;
            }
            if (mp.count(chari)) {
                ans[mp[chari]].push_back({strs[i]});
            } else {
                
                mp[chari]= ind;
                ind++;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};
