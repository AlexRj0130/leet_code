#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } 

        int maxSum = root->val;
        dfs(root, maxSum);

        return maxSum;
    }
private:
    int dfs(TreeNode *root, int &maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int rootVal = root->val;
        int rootSumLeft = dfs(root->left, maxSum);
        int rootSumRight = dfs(root->right, maxSum);

        // 寻找中间子树中的最大路径
        // 中间子树的最大路径，可能仅包含树的根节点 or 根节点+左子树 or 根节点+右子树
        maxSum = max(maxSum, rootVal);
        maxSum = max(maxSum, rootVal + rootSumLeft);
        maxSum = max(maxSum, rootVal + rootSumRight);
        maxSum = max(maxSum, rootVal + rootSumLeft + rootSumRight);

        // 寻找中间子树作为最终最大路径的一部分时，其子最大路径
        // 如果中间子树的路径的 sum 小于等于 0，则全部丢弃
        int ret = 0;  
        ret = max(ret, rootVal);
        ret = max(ret, rootVal + rootSumLeft);
        ret = max(ret, rootVal + rootSumRight);

        return ret;
    }
};
// @lc code=end

