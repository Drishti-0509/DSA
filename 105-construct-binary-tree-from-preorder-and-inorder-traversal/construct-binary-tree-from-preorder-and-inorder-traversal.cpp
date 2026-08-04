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
unordered_map<int,int>mp ;
int preindex = 0;
TreeNode*solve( vector<int>& preorder,vector<int>& inorder ,int instart,int inend){
    if(instart>inend){
        return NULL;
    }
    int rootval =preorder[preindex++] ;
    TreeNode* root = new TreeNode(rootval) ;
    int pos =mp[rootval] ;

      root->left =  solve(preorder,inorder,instart,pos-1) ;
      root->right = solve(preorder,inorder,pos+1,inend) ;
      return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0 ;i<inorder.size() ;i++){
            mp[inorder[i]] =i  ;
        }
         return solve(preorder,inorder,0,inorder.size()-1) ;
    }
};