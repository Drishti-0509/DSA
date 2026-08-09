class Solution {
public:
void dfs(int node,vector<vector<int>>& stones,vector<int>& visited){
    visited[node] =1;
    for(int i= 0;i<stones.size() ;i++){
        if(!visited[i] && (stones[node][0] == stones[i][0] || stones[node][1] == stones[i][1])){
            dfs(i ,stones,visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
     int n = stones.size();
     vector<int> visited(n,0);
     int component = 0;
     for(int i=0 ;i<n ;i++){
        if(!visited[i]){
            component++ ;
            dfs(i,stones,visited);
        }
     }
     return n- component;

    }
};