class Solution {
   public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = heights.size();
        int m = heights[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                heights[nrow][ncol] >= heights[row][col] && !vis[nrow][ncol]) {
                dfs(nrow, ncol, heights, vis);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, p);
            dfs(i, m - 1, heights, a);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, p);
            dfs(n - 1, j, heights, a);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && a[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
