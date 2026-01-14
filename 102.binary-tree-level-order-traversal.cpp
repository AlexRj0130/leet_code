#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

struct QueueNode {
    TreeNode * treeNode; 
    int nodeLevel;

    QueueNode(TreeNode * node, int level) : treeNode(node), nodeLevel(level) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> res;
        std::queue<QueueNode> queue;
        queue.push({root, 0});

        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();

            if (node.treeNode->left != nullptr) {
                queue.push({node.treeNode->left, node.nodeLevel + 1});
            }
            if (node.treeNode->right != nullptr) {
                queue.push({node.treeNode->right, node.nodeLevel + 1});
            }

            while (res.size() <= node.nodeLevel) {
                res.push_back(vector<int>());
            }

            res[node.nodeLevel].push_back(node.treeNode->val);
        }

        return res;
    }
};
// @lc code=end

int main() {
    auto root = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(4),
            nullptr
        ),
        new TreeNode(
            3,
            nullptr,
            new TreeNode(5)
        )
    );

    Solution sol;
    sol.levelOrder(root);
}

