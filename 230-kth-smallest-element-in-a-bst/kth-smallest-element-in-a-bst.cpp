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
    void Vector_push(TreeNode* root,vector<int>& ans){
        if(!root)return;
        Vector_push(root->left,ans);
        ans.push_back(root->val);
        Vector_push(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        Vector_push(root,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};