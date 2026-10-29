class Solution {
public:
    int longestValidParentheses(string s) {
     int count =0 ;
      int maxlength = 0 ;
      int open = 0;
       int close =0 ;
       int n = s.length() ;
       //left to right
      for(int i= 0; i<n ;i++){
if(s[i] == '('){
    open++ ;
}
else{
    close++ ;

}
if(open == close){
  maxlength = max(maxlength , open+close) ;
}
if(close>open){
    open =0 ;
    close =0 ;
}

      }

      //right to left
      open =0 ;
      close=0 ;
      for(int i=n-1 ;i>=0 ;i--){
        if(s[i] == '('){
            open++ ;
        }
        else{
            close++ ;
        }
        if(open == close){
            maxlength = max(maxlength , open+close) ;
        }
        if(open>close){
            close =0 ;
            open =0 ;
        }
      }
     return maxlength;
    }
};