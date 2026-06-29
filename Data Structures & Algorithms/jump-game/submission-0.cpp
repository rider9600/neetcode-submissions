class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> vis(n, 0);
        queue<int> q;

        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= n - 1) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == 0)
                return true;

            for (int i = cur - 1; i >= 0; i--) {
                if (!vis[i] && i + nums[i] >= cur) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

        return n == 1;
    }
};