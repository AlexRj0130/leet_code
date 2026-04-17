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
        int min, max;
        return isBST(root, min, max);
    }
private:
    bool isBST(TreeNode *node, int &min, int &max) {
        if (node == nullptr) {
            return true;
        }

        min = max = node->val;
        if (node->left != nullptr) {
            int tmpMin = 0, tmpMax = 0;
            if ((!isBST(node->left, tmpMin, tmpMax)) || node->val <= tmpMax) {
                return false;
            }
            min = tmpMin;
        }

        if (node->right != nullptr) {
            int tmpMin = 0, tmpMax = 0;
            if ((!isBST(node->right, tmpMin, tmpMax)) || node->val >= tmpMin) {
                return false;
            }
            max = tmpMax;
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