/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;
        count += pathSumHelper(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }

private:
    int pathSumHelper(TreeNode* root, long long targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;
        if (root->val == targetSum) {
            ++count;
        }

        count += pathSumHelper(root->left, targetSum - root->val);
        count += pathSumHelper(root->right, targetSum - root->val);
        return count;
    }
};
// @lc code=end

int main() {
    auto root = new TreeNode(1, 
                    nullptr, 
                    new TreeNode(2, 
                        nullptr,
                        new TreeNode(3, 
                            nullptr, 
                            new TreeNode(4, 
                                nullptr, 
                                new TreeNode(5))))
                );
    Solution sol;
    sol.pathSum(root, 3);
    return 0;
}