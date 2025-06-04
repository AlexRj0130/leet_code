#include <vector>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res; 
        if (n <= 0) {
            return res;
        }

        generateSubTree(1, n, true, res);
        return res;
    }

private:
    vector<TreeNode*> generateSubTree(int start, int end, bool isRoot, vector<TreeNode*> &res) {
        if (start >= end) {
            auto node = new TreeNode(end);
            if (isRoot) {
                res.push_back(node);
            }
            return vector<TreeNode*>({node});
        }

        vector<TreeNode*> subRes;
        for (int midVal = start; midVal <= end; ++midVal) {
            vector<TreeNode*> leftVec, rightVec;
            TreeNode *right = nullptr;
            if (midVal != start) {
                leftVec = generateSubTree(start, midVal - 1, false, res);
            }
            if (midVal != end) {
                rightVec = generateSubTree(midVal + 1, end, false, res);
            }

            if (leftVec.size() > 0 && rightVec.size() > 0) {
                for (const auto & leftNode: leftVec) {
                    for (const auto & rightNode: rightVec) {
                        auto midNode = new TreeNode(midVal, leftNode, rightNode);
                        if (isRoot) {
                            res.push_back(midNode);
                        }
                        subRes.push_back(midNode);
                    }
                }
            } else if (leftVec.size() > 0) {
                for (const auto & leftNode: leftVec) {
                    auto midNode = new TreeNode(midVal, leftNode, nullptr);
                    if (isRoot) {
                        res.push_back(midNode);
                    }
                    subRes.push_back(midNode);
                }
            } else if (rightVec.size() > 0) {
                for (const auto & rightNode: rightVec) {
                    auto midNode = new TreeNode(midVal, nullptr, rightNode);
                    if (isRoot) {
                        res.push_back(midNode);
                    }
                    subRes.push_back(midNode);
                }
            }
        }

        return subRes;
    }
};
// @lc code=end

int main() {
    Solution sol;
    sol.generateTrees(3);
    return 0;
}

