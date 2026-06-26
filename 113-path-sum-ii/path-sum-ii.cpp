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
    vector<vector<int>> ans;
    vector<int>check;
    void push(TreeNode* root,int targetSum){
        if(!root)return;
        check.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum==root->val)ans.push_back(check);
        }
        push(root->left,targetSum-root->val);
        push(root->right,targetSum-root->val);
        check.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        push(root,targetSum);
        return ans;
    }
};