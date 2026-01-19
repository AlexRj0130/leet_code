#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); 
    }
private:
    TreeNode * buildTreeHelper(const vector<int>& inorder, const int inSta, const int inEnd, const vector<int>& postorder, const int postSta, const int postEnd) {
        if (inSta > inEnd || inSta < 0 || inEnd >= inorder.size()) {
            return nullptr;
        }

        if (inSta == inEnd) {
            return new TreeNode(inorder[inSta]);
        }

        int rootVal = -1;
        if (!findRootFromPostOrder(postorder, postSta, postEnd, rootVal)) {
            return nullptr;
        }

        int leftSize = 0, rightSize = 0;
        if (!splitFromInOrder(inorder, inSta, inEnd, rootVal, leftSize, rightSize)) {
            return nullptr;
        }

        auto rootNode = new TreeNode(rootVal);
        rootNode->left = buildTreeHelper(inorder, inSta, inSta + leftSize - 1, postorder, postSta, postSta + leftSize - 1);
        rootNode->right = buildTreeHelper(inorder, inEnd - rightSize + 1, inEnd, postorder, postEnd - rightSize, postEnd - 1);
        return rootNode;
    }

    bool findRootFromPostOrder(const vector<int>& postorder, const int sta, const int end, int &res) {
        if (sta > end || sta < 0 || end >= postorder.size()) {
            return false;
        }

        res = postorder[end];
        return true;
    }

    bool splitFromInOrder(const vector<int>& inorder, const int sta, const int end, const int rootVal, int &resLeftSize, int &resRightSize) {
        if (sta > end || sta < 0 || end >= inorder.size()) {
            return false;
        }

        int targetIndex = -1;
        for (int i = sta; i <= end; ++i) {
            if (inorder[i] == rootVal) {
                targetIndex = i; 
                break;
            }
        }

        if (targetIndex < 0) {
            return false;
        }

        resLeftSize = targetIndex - sta;
        resRightSize = end - targetIndex;
        return true;
    }

};
// @lc code=end

int main() {
    auto inorder = vector<int>{9,3,15,20,7};
    auto postorder = vector<int>{9,15,7,20,3};

    Solution sol;
    sol.buildTree(inorder, postorder);

    return 0;
}