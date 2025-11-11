#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        vector<int> res1, res2; 
        inOrder(root->left, res1, 1000, 1);
        inOrderRev(root->right, res2, 1000, 1);

        return res1 == res2;
    }
private:
    void inOrder(TreeNode* node, vector<int> &res, int flagVal, int depth) {
        if (node == nullptr) {
            res.push_back(flagVal * depth);
            return;
        }

        inOrder(node->left, res, 1000, depth + 1);
        res.push_back(node->val);
        inOrder(node->right, res, -1000, depth + 1);
    }

    void inOrderRev(TreeNode* node, vector<int> &res, int flagVal, int depth) {
        if (node == nullptr) {
            res.push_back(flagVal * depth);
            return;
        }

        inOrderRev(node->right, res, 1000, depth + 1);
        res.push_back(node->val);
        inOrderRev(node->left, res, -1000, depth + 1);
    }
};
// @lc code=end

int main() {
    auto root = new TreeNode(
        2, 
        new TreeNode(3,
            new TreeNode(4),
            new TreeNode(5,
                new TreeNode(8),
                new TreeNode(9))),
        new TreeNode(3,
            new TreeNode(5,
                new TreeNode(9),
                new TreeNode(8)),
            new TreeNode(4))
    );

    Solution sol;
    sol.isSymmetric(root);

    return 0;
}
