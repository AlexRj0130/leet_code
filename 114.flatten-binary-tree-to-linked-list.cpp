/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        } 

        auto curNode = root;
        while (curNode != nullptr) {
            if (curNode->left == nullptr && curNode->right == nullptr) {
                break;
            } else if (curNode->left == nullptr && curNode->right != nullptr) {
                curNode = curNode->right;
                continue;
            } else if (curNode->left != nullptr && curNode->right == nullptr) {
                curNode->right = curNode->left;
                curNode->left = nullptr;
                curNode = curNode->right;
            } else {
                auto rightMost = findRightMost(curNode->left);
                rightMost->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = nullptr;
                curNode = curNode->right;
            }
        }
    }
private:
    TreeNode * findRightMost(TreeNode *node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
};
// @lc code=end

