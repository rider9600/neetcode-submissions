class Solution {
   public:
    int ma = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int* curr) {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                (*curr)++;
                ma = max((*curr), ma);
                dfs(grid, i + 1, j,curr);
                dfs(grid, i - 1, j,curr);
                dfs(grid, i, j + 1,curr);
                dfs(grid, i, j - 1,curr);
            }
        }
        return;
    }
    int numIslands(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans++;
                    int curr = 0;
                    dfs(grid, i, j, &curr);
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        numIslands(grid);
        return ma;
    }
};
