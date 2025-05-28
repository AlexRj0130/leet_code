#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> queueTmp;
        stack<TreeNode*> stackTmp;

        stackTmp.push(root);
        int queueLevel = 0;
        
        while(queueTmp.empty() == false || stackTmp.empty() == false) {
            if (queueTmp.empty()) {
                while(!stackTmp.empty()) {
                    queueTmp.push(stackTmp.top());
                    stackTmp.pop();
                }

                res.push_back(vector<int>{});
                ++queueLevel;
            }

            auto qNode = queueTmp.front();
            queueTmp.pop();

            res[queueLevel - 1].push_back(qNode->val);
            if (queueLevel % 2) {
                if (qNode->left) {
                    stackTmp.push(qNode->left);
                }
                if (qNode->right) {
                    stackTmp.push(qNode->right);
                } 
            } else {
                if (qNode->right) {
                    stackTmp.push(qNode->right);
                } 
                if (qNode->left) {
                    stackTmp.push(qNode->left);
                }
            }
        }

        return res;
    }
};
// @lc code=end

