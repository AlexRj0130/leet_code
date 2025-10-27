#include <vector>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderVal2Index.insert({inorder[i], i}); 
        } 

        return buildSubTree(preorder, 0, inorder, 0, inorder.size());
    }
private:
    TreeNode* buildSubTree(const vector<int>& preorder, int preStart, const vector<int>& inorder, int inStart, int size) {
        if (size <= 0) {
            return nullptr;
        }

        int rootVal = preorder[preStart]; 
        if (size == 1) {
            return new TreeNode(rootVal);
        }

        int rootIndex = inorderVal2Index[rootVal];

        int sizeOfLeft = rootIndex - inStart;
        int sizeOfRight = size - sizeOfLeft - 1;
        TreeNode * subTreeLeft = buildSubTree(preorder, preStart + 1, inorder, inStart, sizeOfLeft);
        TreeNode * subTreeRight = buildSubTree(preorder, preStart + 1 + sizeOfLeft, inorder, inStart + 1 + sizeOfLeft, sizeOfRight);

        return new TreeNode(rootVal, subTreeLeft, subTreeRight);
    }
private:
    unordered_map<int, int> inorderVal2Index;
};
// @lc code=end

int main() {
    vector<int> preorder = {1, 2}, inorder = {2, 1};
    Solution sol;
    auto res = sol.buildTree(preorder, inorder);

    return 0;
}