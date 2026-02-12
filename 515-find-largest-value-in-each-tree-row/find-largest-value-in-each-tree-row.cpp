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
    void levelorder(TreeNode* root,int level,vector<vector<int>>& ans){
        if(!root)return;
        if(ans.size()<=level)ans.push_back({});
        levelorder(root->left,level+1,ans);
        ans[level].push_back(root->val);
        levelorder(root->right,level+1,ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>>ans;
        int level = 0;
        levelorder(root,0,ans);
        vector<int> result;
        for (auto &level : ans) {
            int maxi = level[0];
            for (int val : level) {
                maxi = max(maxi, val);
            }
            result.push_back(maxi);
        }

        return result;

    }
};