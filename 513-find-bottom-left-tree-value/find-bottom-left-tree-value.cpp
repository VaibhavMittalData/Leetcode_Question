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
    void levelorder(TreeNode* root,vector<vector<int>>& ans,int level){
        if(!root)return;
        if(ans.size()==level)ans.push_back({});
        levelorder(root->left,ans,level+1);
        ans[level].push_back(root->val);
        levelorder(root->right,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>>ans;
        levelorder(root,ans,0);
        int size = ans.size();
        return ans[size-1][0];
    }
};