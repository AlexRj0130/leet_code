#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

struct TreeNodeWithDepth {
    TreeNode *node;
    int depth;
    TreeNodeWithDepth(TreeNode *node, int depth) : node(node), depth(depth) {} 
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        } 

        vector<int> res;

        queue<TreeNodeWithDepth> nodeQueue;
        nodeQueue.push(TreeNodeWithDepth(root, 0));
        int preDepth = 0, preVal = root->val;
        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();

            if (preDepth != node.depth) {  // 当深度发生变化的时候，preVal 中就是上一层最右侧节点的值。
                res.push_back(preVal);
            }
            preVal = node.node->val;
            preDepth = node.depth;

            if (node.node->left != nullptr) {
                nodeQueue.push(TreeNodeWithDepth(node.node->left, node.depth + 1));
            }

            if (node.node->right != nullptr) {
                nodeQueue.push(TreeNodeWithDepth(node.node->right, node.depth + 1));
            }
        }
        res.push_back(preVal); // 最后一层最右侧的节点的值。

        return res;
    }
};
// @lc code=end

