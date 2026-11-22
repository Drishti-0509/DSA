class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0 ;
        int  j = 0;
       
        int sum=0 ;
        while(j<k){
            sum +=nums[j] ;
            j++ ;

        }
        int maxi = sum ;
        while(j<nums.size()){
            sum += nums[j] ;
            sum -= nums[i] ;
            i++ ;
            j++ ;
            if(sum>maxi){
                maxi = sum ;
            }
        }
        return (double)maxi/ k ;
    }
};