class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size() ;
        int count =0 ;
        unordered_map<int,int>mp ;

        for(int i = 0 ; i< n ;i++){
            int sum = nums1[i] ;
            for(int j = 0 ; j< n ;j++){
sum +=  nums2[j] ;
mp[sum]++ ;
sum -= nums2[j] ;
            }
        }

        for(int i = 0 ; i< n ;i ++){
            int sum = nums3[i] ;
            for(int j = 0 ; j< n ;j++){
sum +=  nums4[j] ;
if(mp.find(-sum) != mp.end()){
count += mp[-sum] ;
}

sum -= nums4[j] ;
            
        }
        }
        return count ;
    }
};