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
    void levelorder(TreeNode* root,int level, vector<vector<int>>&ans){
        if(!root)return;
        if(ans.size()<=level)ans.push_back({});
        levelorder(root->left,level+1,ans);
        ans[level].push_back(root->val);
        if(ans.size()<=level)ans.push_back({});
        levelorder(root->right,level+1,ans);
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>>ans;
        levelorder(root,0,ans);
        int maxSum = INT_MIN;
        int answerLevel = 0;
          for (int i = 0; i < ans.size(); i++) {
            int sum = 0;
            for (int val : ans[i]) {
                sum += val;
            }
            if (sum > maxSum) {
                maxSum = sum;
                answerLevel = i + 1; 
            }
        }
        return answerLevel;
    }
};