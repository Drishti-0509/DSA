class Solution {
public:
int solve(int i , int buy ,vector<int>& prices , vector<vector<vector<int>>>& dp, int k){
    int n = prices.size() ;
    if(k==0){
        return 0 ;

    }
    if(i == n){
        return 0 ;
    }
    if(dp[i][buy][k] != -1){
        return dp[i][buy][k]  ;
    }
    int profit = 0 ;
    if(buy ==0){
        int buy = -prices[i] + solve(i+1,1,prices,dp,k) ;
        int skip = solve(i+1,0,prices,dp,k) ;
        profit = max(buy,skip);
    }
    if(buy==1){
        int sell = +prices[i] + solve(i+1 ,0,prices,dp ,k-1) ;
        int skip = solve(i+1,1,prices,dp,k) ;
        profit = max(skip, sell) ;
    }
    return dp[i][buy][k] = profit ;

}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
       vector<vector<vector<int>>> dp(
    n, vector<vector<int>>(2, vector<int>(k + 1, -1))
);
        return solve(0,0,prices,dp,k);
    }
};