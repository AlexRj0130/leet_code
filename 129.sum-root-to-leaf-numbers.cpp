/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    // 递归函数：node为当前节点，cur_sum为当前路径拼接的数字
    int dfs(TreeNode* node, int cur_sum) {
        if (node == nullptr) return 0; // 空节点，贡献0
        cur_sum = cur_sum * 10 + node->val; // 更新当前路径数字
        // 叶子节点，返回当前拼接的数字
        if (node->left == nullptr && node->right == nullptr) {
            return cur_sum;
        }
        // 递归处理左右子树，累加结果
        return dfs(node->left, cur_sum) + dfs(node->right, cur_sum);
    }
};
// @lc code=end

