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
void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
TreeNode* buildBST(int left, int right, vector<int>& v) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildBST(left, mid - 1, v);
        root->right = buildBST(mid + 1, right, v);
        return root;
    }
TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return buildBST(0, v.size() - 1, v);
    }
};
