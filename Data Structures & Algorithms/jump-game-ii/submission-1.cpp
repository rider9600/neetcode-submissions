class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        int ans = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= n - 1) {
                q.push({i, 1});
                vis[i] = 1;
            }
        }
        while (!q.empty()) {
           
           
          
           auto [cur, cnt] = q.front();
             cout<<cur<<" "<<cnt<<" "<<ans<<endl;
            q.pop();
            if (cur == 0) {
                ans = min(ans, cnt);
            }
            for (int i = cur - 1; i >= 0; i--) {
                if (!vis[i] && i + nums[i] >= cur) {
                    vis[i] = 1;
                    q.push({i, cnt + 1});
                }
            }
        }
        
        return ans ;
    }
};
