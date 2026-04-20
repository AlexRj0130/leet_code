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
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* rootLeft, TreeNode* rootRight) {
        if (rootLeft == nullptr && rootRight == nullptr) {
            return true;
        } else if (rootLeft == nullptr && rootRight != nullptr) {
            return false;
        } else if (rootLeft != nullptr && rootRight == nullptr) {
            return false;
        }

        if (!isSymmetric(rootLeft->left, rootRight->right)) {
            return false;
        }

        if (rootLeft->val != rootRight->val) {
            return false;
        }

        return isSymmetric(rootLeft->right, rootRight->left);
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
