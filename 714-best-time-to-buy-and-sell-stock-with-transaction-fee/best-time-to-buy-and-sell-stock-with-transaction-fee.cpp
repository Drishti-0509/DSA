class Solution {
public:
int solve(int i , int buy,vector<int>&prices , vector<vector<int>>&dp,int fee){
    int n = prices.size() ;
    if(i >= n){
        return 0 ;
    }
    if(dp[i][buy] != -1){
        return dp[i][buy] ;
    }
    int profit =0 ;
    if(buy == 0){
        int skip =solve(i+1,0,prices,dp,fee) ;
        int buy = -prices[i] + solve(i+1 , 1,prices,dp,fee);
    profit = max(buy,skip) ;
    }
    if(buy ==1){
        int sell = prices[i] -fee +solve(i+1 ,0,prices,dp,fee) ;
        int skip = solve(i+1 ,1,prices,dp,fee);
      profit = max(sell,skip) ;
    }
    return dp[i][buy] = profit ;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>>dp(n, vector<int>(2,-1)) ;
      return solve(0,0,prices,dp,fee) ;
    
    }
};