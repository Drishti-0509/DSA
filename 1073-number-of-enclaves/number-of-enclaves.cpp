class Solution {
public:
void dfs(int row,int col ,vector<vector<int>>& grid  , vector<vector<int>>& vis ){
    int m = grid.size();
    int n =grid[0].size();
    vis[row][col] =1 ;
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    for(int k =0;k<4 ;k++){
        int nr = row + dr[k];
        int nc = col +dc[k];
        if(nr>=0 && nr<m && nc>=0  && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
            dfs(nr,nc,grid,vis) ;
               
            
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));

        for(int i = 0 ;i<m ;i++){
            if(grid[i][0] ==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][n-1] && !vis[i][n-1]){
                dfs(i,n-1,grid,vis) ;
            }
        }
for(int j =0 ;j<n ;j++){
    if(grid[0][j]==1 && !vis[0][j]){
        dfs(0,j,grid,vis);
    }
    if(grid[m-1][j] == 1 && !vis[m-1][j]){
        dfs(m-1,j,grid,vis);
    }
}
int count  =0 ;

for(int i= 0;i<m ;i++){
    for(int j = 0 ;j<n ;j++){
        if(grid[i][j] ==1 && !vis[i][j]){
            count++ ;
        }
    }
}

return count;

    }
};