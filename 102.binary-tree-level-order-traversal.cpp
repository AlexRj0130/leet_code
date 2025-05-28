#include <vector>
#include <queue>

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
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        if (root == nullptr) {
            return res;
        }

        queue<std::pair<TreeNode*, int>> q;
        q.push({root, 1});
        int curLevel = 0;

        while (!q.empty()) {
            auto pNode = q.front(); 
            q.pop();

            if (pNode.second != curLevel) {
                res.push_back(vector<int>{});
                curLevel = pNode.second;
            }
            res[curLevel - 1].push_back(pNode.first->val);

            if (pNode.first->left != nullptr) {
                q.push({pNode.first->left, curLevel + 1});
            }

            if (pNode.first->right != nullptr) {
                q.push({pNode.first->right, curLevel + 1});
            }
        }

        return res;
    }
};
// @lc code=end

