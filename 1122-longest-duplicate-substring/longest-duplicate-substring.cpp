class Solution {
public:
long long calculateHash(string s ,int len ,long long MOD ){
    long long hash = 0 ;
for(int i = 0 ;i<len ;i++){
    
    int val = s[i]-'a'+1 ;
    hash = ((hash*26) +  val) % MOD ;

}
return hash ;
        }
    string longestDupSubstring(string s) {
        int n = s.length() ;
        int low = 1 ;
        int high = n-1 ;
        string ans="" ;
        long long MOD = 1000000007;


        while(low<=high){

            bool found = false ;
          unordered_map<long long, vector<int>> mp;

int mid = low+(high-low)/2 ;
long long power =1;
for(int j = 1; j < mid; j++) {
    power = (power *26)% MOD;
}

 long long hash = calculateHash(s, mid,MOD);
 mp[hash].push_back(0) ;// starting index
 for(int i= 1 ;i<=n-mid ;i++ ){
 int newVal = s[i+mid-1] -'a' +1 ;
int oldVal = s[i-1]-'a'+1 ;
         hash = (hash - (oldVal * power) % MOD + MOD) % MOD;

hash = (hash * 26 + newVal) % MOD;

        if(mp.find(hash) != mp.end()){
            for(int previousIndex :mp[hash]){
            if(s.compare(previousIndex, mid, s, i, mid) == 0){
            found = true ;
            ans = s.substr(i, mid);
            break ;
            }

        }
        
        }

        if(found){
break ;

        }
        mp[hash].push_back(i) ;

 }
        if(!found){
            high=mid-1 ;
        }
       
        else{
            low= mid+1 ;
        }
        }
        return ans;
    }
};