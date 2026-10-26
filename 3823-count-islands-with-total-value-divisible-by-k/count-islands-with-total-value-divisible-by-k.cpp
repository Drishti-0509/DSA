class Solution {
public:
void dfs(vector<vector<int>>& grid , int r, int c, long long & sum){
    
if(r<0 || c<0 || r>= grid.size() || c>= grid[0].size()){
    return ;
}
    if(grid[r][c] == 0){
        return ;
    }
    sum += grid[r][c] ;
    grid[r][c] = 0 ;
    dfs(grid,r+1,c,sum);
    dfs(grid,r,c+1,sum) ;
    dfs(grid,r,c-1,sum) ;
    dfs(grid,r-1,c,sum) ;

}
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0 ;
        for(int i =0 ;i<grid.size() ;i++){
            for(int j=0 ;j<grid[0].size() ;j++){
               
                if(grid[i][j]>0){
                    long long sum =0 ;
                dfs(grid,i,j,sum) ;
                if(sum%k == 0){
                    count++ ;
                }
                }
            }
        } 
        return count ;
           }
};