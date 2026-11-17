class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp ;
       int n =nums.size() ;
       for(int i= 0;i<n ;i++){
        mp[nums[i]]++ ;
       }
       vector<pair<int,int>>v(mp.begin() ,mp.end()) ;
       sort(v.begin(), v.end(), [](auto a, auto b) {
    return a.second > b.second;
});
int i= 0 ;
vector<int>ans;
for(auto it :v){
if(i==k){
    break;
}
ans.push_back(it.first) ;
i++ ;
    }
    
    
    return ans;
    }
};
