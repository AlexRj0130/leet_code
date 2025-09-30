#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q); 
        TreeNode* res;
        for (int i = 0; i < pStack.size() && i < qStack.size(); ++i) {
            if (pStack[i] == qStack[i]) {
                res = pStack[i];
                continue;
            }
            break;
        }

        return res;
    }

private:
    void dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr || (pStack.size() != 0 && qStack.size() != 0)) {
            return;
        } 

        read.push_back(node);

        if (node == p) {
            pStack = read;
        }

        if (node == q) {
            qStack = read;
        }

        dfs(node->left, p, q);
        dfs(node->right, p, q);
        read.pop_back();
    }

private:
    vector<TreeNode*> read, pStack, qStack;
};
// @lc code=end

