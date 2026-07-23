class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0 ;
        int right=0;
        unordered_set<int>st;
        int max_len = 0 ;
        while(right<s.size()){
if(!st.count(s[right])){
    st.insert(s[right]) ;
    max_len= max(max_len,right-left+1) ;
    right++ ;
}
else{
    st.erase(s[left]);
    left++ ;
}

        }
        return max_len ;
    }
};