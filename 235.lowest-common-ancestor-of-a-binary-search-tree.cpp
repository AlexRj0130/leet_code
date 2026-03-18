#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
        if (root == nullptr || p == nullptr || q == nullptr) {
            return nullptr;
        }

        vector<TreeNode*> traceP, traceQ;
        if (!findInTree(root, p->val, traceP)) {
            return nullptr;
        }
        if (!findInTree(root, q->val, traceQ)) {
            return nullptr;
        }

        int resIndex = 0;
        for (int i = 0; i < traceP.size() && i < traceQ.size(); ++i) {
            if (traceP[i] == traceQ[i]) {
                resIndex = i;
            } else {
                break;
            }
        }

        return traceP[resIndex];
    }
private:
    bool findInTree(TreeNode* node, int target, vector<TreeNode*> &trace) {
        if (node == nullptr) {
            return false;
        }

        trace.push_back(node);
        if (node->val == target) {
            return true;
        } else if (node->val > target) {
            return findInTree(node->left, target, trace);
        } else {
            return findInTree(node->right, target, trace);
        }
    }
};
// @lc code=end

