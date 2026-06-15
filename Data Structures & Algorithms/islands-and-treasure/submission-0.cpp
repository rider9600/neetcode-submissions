class Solution {
   public:
    void bfs(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        q.push({sr, {sc,1}});
        vis[sr][sc] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
           
            auto front = q.front();

            int r = front.first;
            int c = front.second.first;
            int val = front.second.second;
            q.pop();
            if (grid[r][c] == -1) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;

                    grid[nr][nc] = min(grid[nr][nc], val);
                    q.push({nr,{ nc,val+ 1}});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j);
                }
            }
        }
    }
};
