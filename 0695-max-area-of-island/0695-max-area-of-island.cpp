class Solution {
public:
    int ans = 0 ;

    void dfs(int i , int j , vector<vector<int>>& grid,vector<vector<bool>>& vis,int& count ){
       int m = grid.size();
       int n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1 || vis[i][j]){
            return;
        }

        vis[i][j] = true;
        count++;
        ans = max(ans, count);

        dfs(i-1,j,grid,vis,count);
        dfs(i+1,j,grid,vis,count);
        dfs(i,j-1,grid,vis,count);
        dfs(i,j+1,grid,vis,count);
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       vector<vector<bool>> vis(m , vector<bool>(n , false));

       for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                int count = 0;
                dfs(i,j,grid,vis,count);
            }
        }
       }     
       return ans;
    }
};