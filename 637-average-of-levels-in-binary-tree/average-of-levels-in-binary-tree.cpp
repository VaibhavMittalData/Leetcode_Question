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
        if(ans.size()==level)ans.push_back({});
        levelorder(root->left,level+1,ans);
        ans[level].push_back(root->val);
        levelorder(root->right,level+1,ans);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>>ans;
        levelorder(root,0,ans);
        vector<double>avg;
        for(int i =0;i<ans.size();i++){
            long long avge = 0;
            for(int j = 0;j<ans[i].size();j++){
                avge+=ans[i][j];
            }
            avg.push_back((double)avge/ans[i].size());
        }
        return avg;
    }
};