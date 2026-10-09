class Solution {
public:
int solve(int i , int state , vector<int> &prices,vector<vector<int>> &dp){
    int n = prices.size() ;
if(i>=n){
    return 0 ;
}
if(dp[i][state] != -1) {
    return dp[i][state];
}
if(state == 0){
    int buy = -prices[i] + solve(i+1,1,prices,dp) ;
    int skip =solve(i+1,0, prices,dp) ;
    return dp[i][state] = max(buy, skip) ;
}
else{
    int sell = +prices[i] + solve(i+2 ,0 , prices,dp) ;
    int skip = solve(i+1,1, prices,dp) ;
    return dp[i][state] = max(sell, skip) ;
}
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>>dp(n , vector<int>(2,-1)) ;
        
        return solve(0,0,prices,dp) ;
    }
};