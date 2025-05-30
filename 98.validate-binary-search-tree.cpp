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
        int minVal, maxVal;
        bool isLeaf;
        return isValidBSTSub(root, isLeaf, minVal, maxVal); 
    }
private:
    bool isValidBSTSub(TreeNode* root, bool &isLeaf, int &minVal, int &maxVal) {
        if (root == nullptr) {
            isLeaf = true;
            return true;
        }

        isLeaf = false;

        bool isSubLeafLeft = false, isSubLeafRight = false;
        int minSubLeft = 0, maxSubLeft = 0, minSubRight = 0, maxSubRight = 0;

        bool isValidLeft = isValidBSTSub(root->left, isSubLeafLeft, minSubLeft, maxSubLeft);
        if (!isValidLeft) {
            return false;
        }
    
        bool isValidRight = isValidBSTSub(root->right, isSubLeafRight, minSubRight, maxSubRight);
        if (!isValidRight) {
            return false;
        }

        if (!isSubLeafLeft) {
            if (maxSubLeft >= root->val) {
                return false;
            }
            minVal = minSubLeft;
        } else {
            minVal = root->val;
        }

        if (!isSubLeafRight) {
            if (minSubRight <= root->val) {
                return false;
            }
            maxVal = maxSubRight;
        } else {
            maxVal = root->val;
        }

        return true;
    }
};
// @lc code=end

