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
        vector<int> res1, res2; 

        leftToRight(root, res1);
        rightToLeft(root, res2);

        return res1 == res2;
    }
private:
    void leftToRight(TreeNode * node, vector<int> &res) {
        if (node == nullptr) {
            return;
        }

        queue<TreeNode *> treeQueue;
        treeQueue.push(node);

        while (!treeQueue.empty()) {
            node = treeQueue.front();
            treeQueue.pop();

            res.push_back(node->val);
            
            if (node->left != nullptr) {
                treeQueue.push(node->left);
            } else {
                res.push_back(-1000);
            }

            if (node->right != nullptr) {
                treeQueue.push(node->right);
            } else {
                res.push_back(1000);
            }
        }
    }

    void rightToLeft(TreeNode * node, vector<int> &res) {
        if (node == nullptr) {
            return;
        }

        queue<TreeNode *> treeQueue;
        treeQueue.push(node);

        while (!treeQueue.empty()) {
            node = treeQueue.front();
            treeQueue.pop();

            res.push_back(node->val);
            
            if (node->right != nullptr) {
                treeQueue.push(node->right);
            } else {
                res.push_back(-1000); 
            }

            if (node->left != nullptr) {
                treeQueue.push(node->left);
            } else {
                res.push_back(1000);
            }
        }
    }
};
// @lc code=end

