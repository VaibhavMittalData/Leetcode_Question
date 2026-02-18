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
    bool ans(TreeNode* root,long max_val,long min_val){
        if(root==NULL)return true;
        if(root->val<=min_val || root->val>=max_val)return false;
        return ans(root->left,root->val,min_val) && ans(root->right,max_val, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return ans(root,LONG_MAX,LONG_MIN);
    }
};