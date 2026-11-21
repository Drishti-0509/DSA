class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp ;
        int maxi = nums[0] ;
        int max_freq =0 ;
        for(int i =0 ;i<nums.size() ;i++){
mp[nums[i]]++ ;
            
if(mp[nums[i]]> max_freq){
    max_freq = mp[nums[i]] ;
    maxi = nums[i] ;
}
            
        }
      

       return maxi ;   
    }
};