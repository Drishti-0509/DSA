class Solution {
public:


    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        unordered_map<int,int>mp ;
for(int i = 0 ;i<n ; i++){
    mp[nums[i]] =i  ;
}



for(int i= 0; i<n ;i++){
  auto it = mp.find(target-nums[i]) ;
    if(it != mp.end() ){
      
        if(  it->second != i){
          
            return {i,it->second};
     
    }


   }

}
return {};
    }
    };