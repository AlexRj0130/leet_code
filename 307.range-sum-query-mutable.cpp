#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start

struct BinTreeNode {
    int val;
    int start;
    int end;
    BinTreeNode* left;
    BinTreeNode* right;
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        updateTree(index, val, root);
    }
    
    int sumRange(int left, int right) {
        return sumTree(left, right, root); 
    }

private:
    int sumTree(int left, int right, BinTreeNode *node) {
        if (left > right || node == nullptr) {
            return 0;
        }

        if (left <= node->start && right >= node->end) {
            return node->val;
        }

        if (left > node->end || right < node->start) {
            return 0;
        }

        return sumTree(left, right, node->left) + sumTree(left, right, node->right);
    }

    void updateTree(int index, int val, BinTreeNode * node) {
        if (node == nullptr) {
            return;
        }

        if (index < node->start || index > node->end) {
            return;
        }

        if (index == node->start && index == node->end) {
            node->val = val;
            return;
        }

        updateTree(index, val, node->left);
        updateTree(index, val, node->right);

        node->val = 0;
        if (node->left != nullptr) {
            node->val += node->left->val;
        }
        if (node->right != nullptr) {
            node->val += node->right->val;
        }
        return;
    }

    BinTreeNode * buildTree(const vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        auto node = new BinTreeNode();
        node->start = start;
        node->end = end;

        if (start == end) {
            node->val = nums[start];
            return node;
        }

        auto mid = (start + end) / 2;
        node->left = buildTree(nums, start, mid);
        node->right = buildTree(nums, mid + 1, end);
        node->val = node->left->val + node->right->val;
        return node;
    }

private:
    BinTreeNode* root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

