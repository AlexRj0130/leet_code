/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        int tmp = 0;
        bool tmpFlag = false;
        return inOrder(root, tmp, tmpFlag, 0);
    }
private:
    bool inOrder(TreeNode* node, int &preVal, bool &hasPreVal, int depth) {
        if (node == nullptr) {
            return true;
        }

        if (!inOrder(node->left, preVal, hasPreVal, depth + 1)) {
            return false;
        }

        if (hasPreVal && node->val <= preVal) {
            return false;
        }
        preVal = node->val;
        hasPreVal = true;

        if (!inOrder(node->right, preVal, hasPreVal, depth + 1)) {
            return false;
        }

        return true;
    }
};
// @lc code=end

int main() {
    TreeNode * root = new TreeNode(1, 
        new TreeNode(1),
        nullptr);

    Solution sol;
    auto res = sol.isValidBST(root);
    
    return 0;
}