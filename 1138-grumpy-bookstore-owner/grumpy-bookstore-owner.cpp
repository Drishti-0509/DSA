class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0 ;
        int j = 0 ;
        int sum =0 ;

        int n= customers.size() ;
        int maxi =0 ;
        int total =0 ;
        for(int k=0 ;k<n ;k++){
            if(grumpy[k] == 0){
            total += customers[k] ;
        }
        }
        while(j<n){
            if(grumpy[j]==1){
            sum += customers[j] ;

            }
            if(j-i+1 > minutes ){
                if(grumpy[i]==1){

                sum -= customers[i] ;
                
            }
            i++;
            }
            if(j-i+1 == minutes){
                if(sum>maxi ){
                    maxi = sum ;
                }

            }
            j++ ;

        }
        return maxi+total ;
    }
};