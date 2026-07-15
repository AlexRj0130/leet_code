#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<pair<TreeNode *, int> *> que;
        que.push(new pair<TreeNode *, int>{root, 0});

        vector<int> res;
        pair<TreeNode *, int> *pre = nullptr;

        while (!que.empty()) {
            auto item = que.front();
            que.pop();

            if (pre != nullptr && item->second != pre->second) {
                res.push_back(pre->first->val);
            }
            pre = item;

            if (item->first->left != nullptr) {
                que.push(new pair<TreeNode *, int>{item->first->left, item->second + 1});
            }
            
            if (item->first->right != nullptr) {
                que.push(new pair<TreeNode *, int>{item->first->right, item->second + 1});
            }
        }

        if (pre != nullptr) {
            res.push_back(pre->first->val);
        }

        return res;
    }
};
// @lc code=end

