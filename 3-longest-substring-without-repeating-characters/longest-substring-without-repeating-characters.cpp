class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j =0 ;
        int n= s.length() ;
        int length=0 ;
        unordered_map<char,int>mp;
        int maxlength = 0;
        while( j<n){
            if(mp.find(s[j]) == mp.end() || mp[s[j]] < i){
             
                mp[s[j]] = j;
               
            }


else{
    i = mp[s[j]]+1 ;
     mp[s[j]] = j;
  
}

 length =j-i
 +1 ;
if(length>maxlength){
    maxlength = length ;
}
 j++;

        }
        return maxlength ;
    }
};