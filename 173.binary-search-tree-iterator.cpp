#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodeAll(root);
    }
    
    int next() {
        auto nodeTmp = nodeStack.top();
        nodeStack.pop();
        pushLeftNodeAll(nodeTmp->right);
        return nodeTmp->val;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }

private:
    void pushLeftNodeAll(TreeNode* root) {
        for (; root != nullptr; root = root->left) {
            nodeStack.push(root);
        }
    }
private:
    stack<TreeNode *> nodeStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

int main() {
    // auto root = new TreeNode(7, 
    //     new TreeNode(3),
    //     new TreeNode(15, 
    //         new TreeNode(9),
    //         new TreeNode(20)));
    auto root = new TreeNode(1);

    BSTIterator iter(root);
    while (iter.hasNext()) {
        auto nextVal = iter.next();
        cout << "val = " << nextVal << endl;
    }
    return 0;
}

