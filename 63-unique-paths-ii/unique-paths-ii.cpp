class Solution {
public:

int solve(int i, int j ,vector<vector<int>>& obstacleGrid ,vector<vector<int>>& dp,int count ){
     int n = obstacleGrid.size() ;
        int m = obstacleGrid[0].size();
       if(obstacleGrid[i][j] == 1){
            return 0 ;
         }
        if(i==n-1 && j==m-1){
            return 1 ;
        }
         if(i>=n || j>=m){
            return 0 ;
         }
         if(dp[i][j] != -1){
            return dp[i][j] ;
         }
         
          int right =0 ;
           int bottom =0 ;
         if( j+1<m && obstacleGrid[i][j+1] == 0 ){
          right = solve(i,j+1,obstacleGrid,dp,count) ;
         }
          if(i+1< n && obstacleGrid[i+1][j] ==0 ){
          bottom = solve(i+1, j, obstacleGrid,dp,count) ;
          }
          return dp[i][j] = right+bottom ;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() ;
        int m = obstacleGrid[0].size();
        int count = 0 ;
        vector<vector<int>>dp(n, vector<int>(m,-1)) ;
        return solve(0,0,obstacleGrid,dp,count) ;
    }
};