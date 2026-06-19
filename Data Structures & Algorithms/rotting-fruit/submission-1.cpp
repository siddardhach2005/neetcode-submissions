class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        bool f=false;
        int c=0;
        int fresh=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2) {
                    q.push({row,col});
                }
                else if(grid[row][col]==1){
                    fresh++;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty() && fresh>0){
            int s=q.size();
            for(int j=0;j<s;j++){
                auto [row,col]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }
            }
            c++;
        }
        if(fresh>0) return -1;
        else return c;
    }
};
