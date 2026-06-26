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
    vector<int>s;
    vector<vector<int>>ans;
    void push(TreeNode* root){
        if(!root)return;
        s.push_back(root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
        }
        push(root->left);
        push(root->right);
        s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        push(root);
        vector<string>res;
        for(int i =0;i<ans.size();i++){
            string p;
            for(int j = 0;j<ans[i].size();j++){
                p+=to_string(ans[i][j]);
                p+="->";
            }
            p.pop_back();
            p.pop_back();
            res.push_back(p);
        }
        return res;
    }
};