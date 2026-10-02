class Solution {
public:
int solve(int i , int j , int m , int n , string &word1 , string &word2 , vector<vector<int>>& dp){
if(i==m){
    return n - j ;
}
if(j== n){
    return m - i  ;
}

    if(dp[i][j] != -1){
        return dp[i][j] ;
    }
if(word1[i] == word2[j]){
    return dp[i][j] = solve(i+1, j+1, m , n , word1, word2, dp) ;
}
return dp[i][j] = 1 + min( {solve(i+1, j+1, m , n , word1 , word2 , dp) , solve(i+1, j , m , n , word1 , word2 , dp) , solve(i, j+1 , m , n, word1,word2 , dp) }) ;
}
    int minDistance(string word1, string word2) {
      int m = word1. size() ;
      int n = word2.size() ;
      vector<vector<int>>dp(m , vector<int>(n,-1)) ;
      return solve(0,0, m , n , word1 , word2, dp )   ;
    }
};