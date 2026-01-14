/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
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
    bool isValidBST(TreeNode* root) {
        int min, max;
        return isValidBSTSub(root, min, max);
    }
private:
    bool isValidBSTSub(TreeNode* root, int &min, int &max) {
        if (root == nullptr) {
            return true;
        }

        min = max = root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        int minLeft = root->val, maxLeft = root->val, minRight = root->val, maxRight = root->val;
        if (root->left != nullptr) {
            if (!isValidBSTSub(root->left, minLeft, maxLeft)) {
                return false;
            }

            if (maxLeft >= root->val) {
                return false;
            }

            min = minLeft;
        }

        if (root->right != nullptr) {
            if (!isValidBSTSub(root->right, minRight, maxRight)) {
                return false;
            }

            if (minRight <= root->val) {
                return false;
            }

            max = maxRight;
        }

        return true;
    }
};
// @lc code=end

