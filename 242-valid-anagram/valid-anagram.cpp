class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

unordered_map<int,int>mp ;

for(int i =0;i<s.size() ;i++){
mp[s[i]]++ ;
     } 
     for(int i=0 ;i<t.size() ;i++){
        if(mp.find(t[i]) != mp.end()){
            mp[t[i]]-- ;
        }
     } 
     for(auto it:mp){
        if(it.second != 0){
            return false;
        }
     }
     return true;

    }
};