#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res; 
        vector<int> record;
        dfs(root, 0, targetSum, record, res);

        return res;
    }
private:
    void dfs(TreeNode* root, int curSum, int targetSum, vector<int> &record, vector<vector<int>> &res) {
        if (root == nullptr) {
            return;
        }

        record.push_back(root->val);
        curSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (curSum == targetSum) {
                res.push_back(record);
            }
            record.pop_back();
            return;
        }

        if (root->left != nullptr) {
            dfs(root->left, curSum, targetSum, record, res);
        }

        if (root->right != nullptr) {
            dfs(root->right, curSum, targetSum, record, res);
        }

        record.pop_back();
    }
};
// @lc code=end

