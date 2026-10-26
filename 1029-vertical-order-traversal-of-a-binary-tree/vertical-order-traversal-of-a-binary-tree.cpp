/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL){
            return {} ; 
        }
       queue<pair<TreeNode* , pair<int,int>>> q ;
     map<int, map<int, multiset<int>>> mp;
       vector<vector<int>> ans;
       q.push({root ,{0,0}}) ;
       while(!q.empty()){
        TreeNode* node = q.front().first ;
int row = q.front().second.first;
int col = q.front().second.second;
mp[col][row].insert(node->val) ;
        q.pop() ;
       
            if(node->left != NULL){
                q.push({node->left ,{row+1, col-1}}) ;
            }
if(node->right != NULL){
    q.push({node->right , {row+1,col+1}}) ;


        }
       }
       for(auto col : mp){
        vector<int>temp ;
        for(auto row : col.second){
            for(int i : row.second){
                temp.push_back(i) ;
            }
        }
        ans.push_back(temp) ;
       }


       return ans;
    }
};