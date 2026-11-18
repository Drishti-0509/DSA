class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int,int>mp ;
      
      int n = nums.size() ;
      int prefixSum = 0 ;
      int maxi = 0;
      int len=0 ;
      mp[0]= -1;
      
      for(int i = 0 ; i<n ; i++){
        if(nums[i] == 0){

prefixSum += -1 ;
        }
        else{
            prefixSum += +1 ;
        }


 if(mp.find(prefixSum) != mp.end() ){
    len = i - mp[prefixSum];
    

 }
 else{
    mp[prefixSum] = i;
 }
 
     if(len>maxi){
        maxi = max(maxi , len) ;

      }


    }
      return maxi ;
    }
};