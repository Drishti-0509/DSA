class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp2;
        unordered_map<char,string> mp1;
        int n= pattern.size() ;
        stringstream ss(s) ;
        string word ;
        int i =0 ;
        while (ss>>word){
            if(i>= n){
    return false;
}
        
            if(mp1.find(pattern[i]) == mp1.end()  && mp2.find(word) == mp2.end()){
                mp1[pattern[i]] = word ;
                mp2[word] = pattern[i] ;
            }
            else{
                if(mp1[pattern[i]] != word || mp2[word] != pattern[i]){
                    return false ;
                }
            }
            i++ ;
        


    }
    if(i!=n){
        return false;
    }
return true ;
    }
        };
       