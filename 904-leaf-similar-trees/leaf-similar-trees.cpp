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
    void Leafvector(TreeNode* root,vector<int>& ans){
        if(!root)return;
        if(root->left==NULL && root->right==NULL)ans.push_back(root->val);
        Leafvector(root->left,ans);
        Leafvector(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        vector<int>r2;
        Leafvector(root1,r1);
        Leafvector(root2,r2);
        return r1==r2;
    }
};