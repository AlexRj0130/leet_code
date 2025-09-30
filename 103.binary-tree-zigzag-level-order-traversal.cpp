#include <queue>
#include <vector>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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

struct QueueNode {
    TreeNode * node; 
    int level;
    QueueNode(TreeNode *pNode, int nodeLevel) : node(pNode), level(nodeLevel) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> res;
        vector<int> resItem;

        queue<QueueNode> readQueue; 
        readQueue.push(QueueNode(root, 0));
        int curLevel = 0;

        stack<QueueNode> tmpStack;
        while(!readQueue.empty()) {
            auto readNode = readQueue.front();
            resItem.push_back(readNode.node->val);
            readQueue.pop();

            if (readNode.level % 2 == 0) {
                if (readNode.node->left != nullptr) {
                    tmpStack.push(QueueNode(readNode.node->left, readNode.level + 1));
                }
                if (readNode.node->right != nullptr) {
                     tmpStack.push(QueueNode(readNode.node->right, readNode.level + 1)); 
                }
            } else {
                if (readNode.node->right != nullptr) {
                     tmpStack.push(QueueNode(readNode.node->right, readNode.level + 1)); 
                }
                if (readNode.node->left != nullptr) {
                    tmpStack.push(QueueNode(readNode.node->left, readNode.level + 1));
                }
            }

            if (readQueue.empty()) {
                while(!tmpStack.empty()) {
                    readQueue.push(tmpStack.top());
                    tmpStack.pop();
                }
                res.push_back(resItem);
                resItem.clear();
            }
        }

        return res;
    }
};
// @lc code=end

