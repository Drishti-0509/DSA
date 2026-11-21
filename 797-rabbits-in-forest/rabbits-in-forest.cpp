class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count=0 ;
        unordered_map<int,int>mp ;
        sort(answers.begin(),answers.end());
        int n=  answers.size() ;
         int group =0 ;
        for(int i=0 ;i<n ;i++){
            
if(mp.find(answers[i]) == mp.end()) {
    group = answers[i]+1 ;
count += group ;
mp[answers[i]] =1 ;
}
           else if(mp[answers[i]]<group){
            mp[answers[i]]++;
           
           
            }
            else{
               group = answers[i]+1 ;
               count += group ;
               mp[answers[i]] =1;
            }



        }
        return count ;
    }
};