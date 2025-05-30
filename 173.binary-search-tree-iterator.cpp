#include <vector>
#include <iostream>

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
        initFlag = true;
        initReadNode(root);
    }
    
    int next() {
        if (initFlag) {
            initFlag = false;
        } else {
            moveNext(readRecord, curIndex);
        }
        return readRecord[curIndex]->val;
    }
    
    bool hasNext() {
        if (curIndex == 0) {
            if (initFlag) {
                return true;
            }
            if (readRecord[curIndex]->right == nullptr) {
                return false;
            }
            return true;
        }

        if (curIndex > 0) {
            if (readRecord[curIndex]->right != nullptr) {
                return true;
            }
        }

        if (readRecord[curIndex - 1]->left == readRecord[curIndex]) {
            return true;
        }

        int curIndexTmp = curIndex;
        while (curIndexTmp > 0 && readRecord[curIndexTmp - 1]->right == readRecord[curIndexTmp]) {
            --curIndexTmp;
        }
        if (curIndexTmp == 0) {
            return false;
        }

        return true;
    }

private:
    void moveNext(vector<TreeNode *> &readRecord, int &curIndex) {
        if (readRecord[curIndex]->right != nullptr) {
            initReadNode(readRecord[curIndex]->right);
            return;
        }
        
        if (curIndex == 0) {
            return;
        }

        while (curIndex > 0 && readRecord[curIndex - 1] -> right == readRecord[curIndex]) {
            --curIndex;
        }
        --curIndex;
    }

    void initReadNode(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        ++curIndex;
        if (curIndex >= readRecord.size()) {
            readRecord.push_back(root);
        } else {
            readRecord[curIndex] = root;
        }

        if (root -> left == nullptr) {
            return;
        }

        initReadNode(root -> left);
    }
private:
    vector<TreeNode *> readRecord;
    int curIndex{-1};
    int initFlag = false;
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

