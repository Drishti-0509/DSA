class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         vector<int>ans ;
        int n = p.size() ;
        int m = s.size() ;
        if(n > m) return ans;
       int i = 0 ;
       int j = 0;
      
       unordered_map<char,int>mp ;
       unordered_map<char,int>slide ;

       while(i<n){
        mp[p[i]]++ ;
        i++ ;
       }

      i=0 ;

      while(j<n){
        slide[s[j]]++ ;
        j++ ;

      }
     
      while(i<=m && j<=m){
        if(mp== slide){
           ans.push_back(i) ;
        }
        slide[s[i]]-- ;
      
        if(slide[s[i]] == 0) {
    slide.erase(s[i]);
}
i++ ;
        
        slide[s[j]]++ ;
        j++ ;

      }
return ans;
    }
};