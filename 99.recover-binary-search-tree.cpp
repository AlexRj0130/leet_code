#include <utility>

/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        inOrder(root);
        if (first != nullptr) {
            if (second != nullptr) {
                std::swap(second->val, firstNext->val);
                return;
            }
            std::swap(first->val, firstNext->val);
        }
    }

private:
    void inOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left);
        if (pre != nullptr) {
            if (pre->val >= root->val) {
                if (first != nullptr) {
                    second = first;
                    secondNext = firstNext;
                } 
                first = pre;
                firstNext = root;
            }
        }
        pre = root;
        inOrder(root->right);
    }

private:
    TreeNode *pre{nullptr}; 
    TreeNode *first{nullptr};
    TreeNode *firstNext{nullptr};
    TreeNode *second{nullptr};
    TreeNode *secondNext{nullptr};
};
// @lc code=end

int main() {
    auto node2 = TreeNode(2);
    auto node3 = TreeNode(3, nullptr, &node2);
    auto node1 = TreeNode(1, &node3, nullptr);

    Solution sol;
    sol.recoverTree(&node1);
}

