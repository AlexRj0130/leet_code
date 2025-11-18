#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res  = 0; 
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* node, int &res) {
        if (node == nullptr) {
            return 0;
        } 

        int leftCount = 0, rightCount = 0;

        if (node->left != nullptr) {
            leftCount = dfs(node->left, res) + 1;
        }

        if (node->right != nullptr) {
            rightCount = dfs(node->right, res) + 1;
        }

        res = max(res, leftCount + rightCount);
        return max(leftCount, rightCount);
    }
};
// @lc code=end

