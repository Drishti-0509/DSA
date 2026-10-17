class Solution {
public:
int solve(int i , int j , vector<vector<char>>& matrix, int & maxi,vector<vector<int>>& dp){
      int n  = matrix.size() ;
        int m = matrix[0].size() ;
        if(i>n-1 || j>m-1){
            return 0 ;
        }
        if(dp[i][j]!= -1){
            return dp[i][j] ;
        }
        int down = solve(i+1,j,matrix,maxi,dp) ;
        int right = solve(i,j+1,matrix, maxi,dp) ;
        int diagonal = solve(i+1,j+1,matrix,maxi,dp) ;

        if(matrix[i][j] == '1'){
             dp[i][j] = 1+ min(down , min(right, diagonal)) ;
            maxi = max(maxi, dp[i][j]) ;

        }
        else{
          dp[i][j] = 0 ;
        }
        return dp[i][j] ;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int n  = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<int>>dp(n , vector<int>(m,-1)) ;
        int maxi = 0 ;
        solve(0,0,matrix, maxi,dp) ;
        
        return maxi*maxi ;
    }
};