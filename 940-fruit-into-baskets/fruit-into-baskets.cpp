class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp ;
        int i = 0;
        int j = 0 ;
        int maxi =0 ;
        int n = fruits.size() ;


        while(j<n){

            if(mp.empty() || (mp.find(fruits[j]) == mp.end() )){
                mp[fruits[j]]++;
                 j++;
               
               

            }
            else if(mp.find(fruits[j]) != mp.end()){
                mp[fruits[j]]++ ;
                 j++;
            }
          

  while(mp.size()>2){
    mp[fruits[i]]-- ;

    if(mp[fruits[i]] == 0){
        mp.erase(fruits[i]) ;
    }
    i++ ;
    


  }
 
  if(j-i > maxi){
    maxi =j-i;
  }

    }
return maxi ;
    }
};