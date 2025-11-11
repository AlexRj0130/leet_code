#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return isBalancedWithHeight(root) >= 0;
    }

private:
    int isBalancedWithHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        auto leftHeight = isBalancedWithHeight(root->left);
        if (leftHeight < 0) {
            return -1;
        }
        auto rightHeight = isBalancedWithHeight(root->right);
        if (rightHeight < 0) {
            return -1;
        }

        if (leftHeight - rightHeight < -1 || leftHeight - rightHeight > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};
// @lc code=end

