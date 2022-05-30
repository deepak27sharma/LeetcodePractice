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
    bool isValidBST(TreeNode* root, TreeNode* l, TreeNode* r) {
        if (root == nullptr) return true;
        else {
            if (l != nullptr && root->val <= l->val) return false;
            if (r != nullptr && root->val >= r->val) return false;
            return isValidBST(root->left, l, root) && isValidBST(root->right, root, r);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};