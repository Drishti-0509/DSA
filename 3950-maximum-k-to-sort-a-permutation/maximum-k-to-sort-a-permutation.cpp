class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n= nums.size() ;
        int ans = -1 ;
        int i=0 ;
        bool misplace = false ;

      while(i<n){
if(nums[i] != i){
misplace = true;
ans = ans & nums[i] ;

}
i++ ;
      }
      if(misplace == false){
        return 0 ;
      }
      return ans;
    }
};