#include <iostream>
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
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        mid(root); 
        auto tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    void midCout(TreeNode * root) {
        if (root == nullptr) {
            return;
        }
        midCout(root->left);
        std::cout << root->val << std::endl;
        midCout(root->right);
    }

private:
    void mid(TreeNode * node) {
        if (node == nullptr) {
            return;
        }

        mid(node->left);
        if (pre == nullptr) {
            pre = node;
        } else {
            if (pre->val > node->val) {
                if (first == nullptr) {
                    first = pre;
                    second = node;
                } else {
                    second = node;
                }
            }
            pre = node;
        }
        mid(node->right);
    }

private:
    TreeNode * first = nullptr;
    TreeNode * second = nullptr;
    TreeNode * pre = nullptr;
};
// @lc code=end

int main() {
    auto root = new TreeNode(3, 
        new TreeNode(1), 
        new TreeNode(4, 
            new TreeNode(2), 
            nullptr));

    Solution sol;
    sol.midCout(root);
    sol.recoverTree(root);
    sol.midCout(root);

    return 0;
}

