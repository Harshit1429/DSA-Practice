class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        int count= 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
        
    }
    void dfs(int i , int j , vector<vector<char>>& grid ,  vector<vector<bool>>& vis){


       if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] != '1'){
          return;
       } 

       vis[i][j] = true;

       dfs(i - 1 , j ,grid,vis);
       dfs(i + 1 , j ,grid,vis);
       dfs(i , j - 1 ,grid,vis);
       dfs(i , j + 1 ,grid,vis);

    }
};