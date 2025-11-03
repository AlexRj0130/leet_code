#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode *> tQueue; 
        tQueue.push(root);
        bool noChildFlag = false;
        while (!tQueue.empty()) {
            auto tmp = tQueue.front();
            tQueue.pop();

            if (noChildFlag) {
                if (tmp->left != nullptr || tmp->right != nullptr) {
                    return false;
                }
            } else {
                if (tmp->left != nullptr) {
                    tQueue.push(tmp->left);
                    if (tmp->right != nullptr) {
                        tQueue.push(tmp->right);
                    } else {
                        noChildFlag = true;
                    }
                } else {
                    noChildFlag = true;
                    if (tmp->right != nullptr) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

