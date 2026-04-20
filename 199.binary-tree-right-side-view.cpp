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
        TreeNodeWithDepth preNode = {root, 0};
        nodeQueuePush(root, 0);

        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();

            if (node.depth != preNode.depth) {
                res.push_back(preNode.node->val);
            }

            nodeQueuePush(node.node, node.depth);
            preNode = node;
        }

        res.push_back(preNode.node->val);
        
        return res;
    }
private:
    void nodeQueuePush(TreeNode *node, int nodeDepth) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            nodeQueue.push({node->left, nodeDepth + 1});
        }

        if (node->right != nullptr) {
            nodeQueue.push({node->right, nodeDepth + 1});
        }
    }

private:
    queue<TreeNodeWithDepth> nodeQueue;
};
// @lc code=end

