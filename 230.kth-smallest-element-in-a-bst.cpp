/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        if (k <= 0) {
            return -1;
        } 

        int res, curIndex = 0;
        if (midTravel(root, curIndex, k, res)) {
            return res;
        }
        return -1;
    }
private:
    bool midTravel(TreeNode* node, int &curIndex, const int targetIndex, int &res) {
        if (node == nullptr) {
            return false;
        }

        if (midTravel(node->left, curIndex, targetIndex, res)) {
            return true;
        }
        ++curIndex;
        if (curIndex == targetIndex) {
            res = node->val;
            return true;
        }
        return midTravel(node->right, curIndex, targetIndex, res);
    }
};
// @lc code=end

