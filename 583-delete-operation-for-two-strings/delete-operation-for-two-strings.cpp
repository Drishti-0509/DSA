class Solution {
public:
int solve(int i , int j ,  string word1 , string word2 , vector<vector<int>>& dp , int m , int n ){
   
    
    if (i == m) {
            return n - j;
        }
        if (j == n) {
            return m - i;
        }

    if(dp[i][j] != -1){
        return dp[i][j] ;
    }
    if(word1[i] == word2[j] ){
        return dp[i][j] = solve(i+1, j+1,word1, word2, dp , m , n) ;
    }
    return dp[i][j] = 1+ min(solve(i+1, j , word1 , word2 ,dp, m, n) , solve(i, j+1, word1, word2, dp, m, n)) ;
}
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;
        vector<vector<int>> dp(m, vector<int>(n , -1)) ;
        return solve(0,0,word1, word2, dp,m ,n) ;
    }
};