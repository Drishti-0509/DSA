class Solution {
public:
    int maxVowels(string s, int k) {
        int i= 0;
        int j =0 ;
        int count=0 ;
        while(j<k){
if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||s[j]== 'o' || s[j] == 'u' ){
    count++; 
}
j++ ;
        }
        int maxi = count ;
while(j<s.size()){
    if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||s[j]== 'o' || s[j] == 'u' ){
        count++ ;
    }
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i]== 'o' || s[i] == 'u' ){
        count-- ;
    }
    i++ ;
    j++;
    if(count>maxi){
        maxi = count ;
    }
}
return maxi ;
    }
};