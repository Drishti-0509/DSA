class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;
        vector<int>prefixSum(nums.size()) ;
prefixSum[0] = nums[0] ;
        int count = 0 ;
        for(int i=1; i<nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] + nums[i] ;

        }
       mp[0]= 1;
       
        for(int i = 0 ; i<nums.size() ;i++){
            int rem = ((prefixSum[i] % k) + k) % k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem] ;

            }
            mp[rem]++ ;
        }
        return count;

    }
};