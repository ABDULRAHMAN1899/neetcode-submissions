class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans = max(ans, dfs(grid,i,j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0;
        int area = 1;

        area = area + dfs(grid,i+1,j);
        area = area + dfs(grid,i-1,j);
        area = area + dfs(grid,i,j+1);
        area = area + dfs(grid,i,j-1);

        return area;
    }
};