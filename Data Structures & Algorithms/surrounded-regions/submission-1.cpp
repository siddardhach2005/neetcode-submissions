class Solution {
   public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, vis, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, vis, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, vis, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, vis, board);
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && board[row][col] == 'O') board[row][col] = 'X';
            }
        }
    }
};
