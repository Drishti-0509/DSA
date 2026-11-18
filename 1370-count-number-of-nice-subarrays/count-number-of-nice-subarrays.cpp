class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size() ;
    unordered_map<int,int>mp ;
    int oddcount=0 ;
    int count = 0 ;
mp[0] = 1;
for(int i =0 ;i<n ;i++){
    if(nums[i]%2 != 0){
       oddcount++ ;
    }
   int target = oddcount-k ;
    if(mp.find(target) != mp.end()){

count += mp[target] ;
        }
        mp[oddcount]++ ;


    } 

    return count;
    }

};