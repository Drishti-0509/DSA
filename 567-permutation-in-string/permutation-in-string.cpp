class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0} ;
        int freq2[26] = {0} ;
        int n= s1.length() ;
        int m= s2.length() ;

        for(int i=0 ;i<n ;i++){
            freq1[s1[i] -'a']++ ;
        } 
        int i =0 ;
        int j = 0 ;
        while(j<m){
            freq2[s2[j]-'a']++ ;
            if(j-i+1>n){
                freq2[s2[i]-'a']-- ;
                i++ ;
            }
            if(j-i+1 == n){
               if(equal(freq1, freq1 + 26, freq2)){
                    return true ;
                }    
               
                        }
                         j++;
        }
        return false;
    }
};