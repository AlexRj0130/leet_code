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

        queue<QueueNode> queue;
        queue.push({root, 0});

        vector<vector<int>> res;
        while(!queue.empty()) {
            vector<int> resItem;
            auto item = queue.front();
            queue.pop();
            resItem.push_back(item.treeNode->val);
            if (item.treeNode->left != nullptr) {
                queue.push({item.treeNode->left, item.nodeLevel + 1});
            }
            if (item.treeNode->right != nullptr) {
                queue.push({item.treeNode->right, item.nodeLevel + 1});
            }

            while((!queue.empty()) && queue.front().nodeLevel== item.nodeLevel) {
                auto sameItem = queue.front();
                queue.pop();
                resItem.push_back(sameItem.treeNode->val);
                if (sameItem.treeNode->left != nullptr) {
                    queue.push({sameItem.treeNode->left, sameItem.nodeLevel + 1});
                }
                if (sameItem.treeNode->right != nullptr) {
                    queue.push({sameItem.treeNode->right, sameItem.nodeLevel + 1});
                }
            }
            res.push_back(resItem);
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

