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
        map<int,vector<pair<int,int>>> mp ;
        if(root == NULL)
    return {};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}}) ;
        while(!q.empty()){
            auto it = q.front() ;
            q.pop();
            TreeNode* node = it.first ;
            int row = it.second.first ;
            int col= it.second.second ;
            mp[col].push_back({row,node->val}) ;
            if(node->left != NULL){
                q.push({node->left,{row+1,col-1}});

            }
            if(node->right){
                q.push({node->right,{row+1,col+1}}) ;
            }

        }
       
        vector<vector<int>> ans;
        for(auto &x:mp){
            sort(x.second.begin(), x.second.end()) ;
            vector<int> temp ;
            for(auto &p : x.second){
                temp.push_back(p.second) ;
            }
ans.push_back(temp) ;
        }

return ans;
    }
};