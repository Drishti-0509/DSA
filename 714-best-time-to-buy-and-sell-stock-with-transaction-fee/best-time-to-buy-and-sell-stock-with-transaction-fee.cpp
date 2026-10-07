class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
       int cash =0 ;
       int hold = 0-prices[0] ;
       for(int i =1 ;i<n ;i++){
        int newcash =max(cash , hold+prices[i]-fee) ;
        int newhold = max(hold , cash-prices[i]) ;
        cash = newcash ;
        hold = newhold;
       }
       return cash;

    }
};