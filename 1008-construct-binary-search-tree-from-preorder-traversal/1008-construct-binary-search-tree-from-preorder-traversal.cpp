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
    /*int firstLargerIndex(vector<int>& preorder, int l, int h, int value) {
        int m = -1;
        while (l <= h) {
            if (l == h) {
                if (preorder[l] > value) return l;
                return -1;
            }
            m = l + (h - l) / 2;
            if (preorder[m] > value) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return larger == INT_MAX ? -1 : larger;
    }*/
    int firstLargerIndex(vector<int>& preorder, int l, int h, int value) {
        int i = l;
        while (i <= h) {
            if (preorder[i] > value) {
                return i;
            }
            i++;
        }
        return -1;
    }
    TreeNode* recoverBst(vector<int>& preorder, int l, int h) {
        if (l <= h) {
            TreeNode* root = new TreeNode(preorder[l]);
            int firstLarger = firstLargerIndex(preorder, l + 1, h, preorder[l]);
            if (firstLarger == -1) {
                //all remaining are less than root.
                root->left = recoverBst(preorder, l + 1, h);
                root->right = nullptr;
            } else {
            root->left = recoverBst(preorder, l + 1, firstLarger - 1);
            root->right = recoverBst(preorder, firstLarger, h);
            }
            return root;
        }
        return nullptr;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int l = 0, h = preorder.size() - 1;
        return recoverBst(preorder, l, h);
    }
};