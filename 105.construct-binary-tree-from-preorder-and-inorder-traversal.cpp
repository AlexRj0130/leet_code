#include <vector>
#include <unordered_map>

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
        if (preorder.size() <= 0) {
            return nullptr;
        }

        int tmp = 0;
        makeInorderVal2Index(inorder);
        return makeSubTree(preorder, tmp, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* makeSubTree(const vector<int>& preorder, int &preorderIndex, const vector<int>& inorder, int inorderLeft, int inorderRight) {
        int rootVal = preorder[preorderIndex];
        int inorderRootIndex = inorderVal2Index[rootVal];

        TreeNode *nodeLeft = nullptr, *nodeRight = nullptr;
        if (inorderRootIndex > inorderLeft) {
            ++preorderIndex;
            nodeLeft = makeSubTree(preorder, preorderIndex, inorder, inorderLeft, inorderRootIndex - 1);
        }
        if (inorderRootIndex < inorderRight) {
            ++preorderIndex;
            nodeRight = makeSubTree(preorder, preorderIndex, inorder, inorderRootIndex + 1, inorderRight);
        }
        
        return new TreeNode(rootVal, nodeLeft, nodeRight);
    }
    void makeInorderVal2Index(const vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderVal2Index.insert({inorder[i], i});
        }
    }
private:
    std::unordered_map<int, int> inorderVal2Index;
};
// @lc code=end

int main() {
    vector<int> preorder{3,1,2,4};
    vector<int> inorder{1,2,3,4};

    Solution sol;
    auto res = sol.buildTree(preorder, inorder);
    return 0;
}

