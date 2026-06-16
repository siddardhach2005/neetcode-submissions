class Solution {
public:
    int ma=0;
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int cnt=1;
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    cnt++;
                }
            }
        }
        ma=max(ma,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]==1){
                    bfs(row,col,vis,grid);
                }
            }
        }
        return ma;
    }
};
