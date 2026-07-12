class Solution {
    int area=0;
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int& area){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=n || row<0 || col>=m || col<0 || grid[row][col]==0 ){
            return;
        }
        vis[row][col]=1;
        area++;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid,area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxarea=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]==1){
                    area=0;
                    dfs(row,col,vis,grid,area);
                    maxarea=max(maxarea,area);

                }
            }
        }
        return maxarea;
    }
};
