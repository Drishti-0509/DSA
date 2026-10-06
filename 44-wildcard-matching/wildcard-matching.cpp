class Solution {
public:
int solve(int i, int j , string &s , string &t , vector<vector<int>> &dp){
if(i < 0 && j < 0){
    return 1;
}

if(j < 0){
    return 0;
}
   
    if(i < 0){
        for(int k = 0; k <= j; k++){
            if(t[k] != '*'){
                return 0;
            }
        }
        return 1;
    }

    if(dp[i][j] != -1){
    return dp[i][j];
}
  if(t[j] == '*'){
    return dp[i][j] = solve(i-1, j, s,t,dp) || solve(i, j-1,s,t,dp) ;

}
 if(t[j] == '?' || s[i] == t[j]) {
    return dp[i][j] =solve(i-1,j-1,s,t,dp);
}
return dp[i][j] = 0;

}
    bool isMatch(string s, string p) {
        int m = s.size() ;
        int n = p.size() ;
        vector<vector<int>>dp(m , vector<int>(n , -1)) ;
        return solve(m-1, n-1, s, p, dp) ;
    }
};