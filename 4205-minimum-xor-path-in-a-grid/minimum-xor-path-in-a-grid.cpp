class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        int MAX_XOR = 1023;
        int m = grid.size() ;
        int n = grid[0].size()  ;
      vector<vector <vector<bool>>>dp(m ,vector<vector<bool>>(n,vector<bool>(MAX_XOR+1 ,false))) ;
      dp[0][0][grid[0][0]] = true ;

      for(int i= 0;i< m ;i++){
        for(int j =0; j<n ;j++){
            for(int k= 0;k<=MAX_XOR ;k++){
                
            if( i>0 && dp[i-1][j][k] == true ){
                int left_xor = k^grid[i][j] ;
                dp[i][j][left_xor] = true ;
            }
            if( j>0 && dp[i][j-1][k] == true){
                int right_xor = k^grid[i][j] ;
                dp[i][j][right_xor] = true;
            }
           
                }
        }
      
}
      
      for (int k = 0; k <= MAX_XOR; k++) {
    if (dp[m-1][n-1][k]) {
        return k;
    }
}
              
            
return 0;

    }
};