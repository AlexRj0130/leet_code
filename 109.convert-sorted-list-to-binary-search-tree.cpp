#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        auto pRead = head;
        vector<ListNode*> nodeList;
        while (pRead)
        {
            nodeList.push_back(pRead);
            pRead = pRead->next;
        }
       
        return buildTreeHelper(nodeList, 0, nodeList.size() - 1);
    }
private:
    TreeNode *buildTreeHelper(const vector<ListNode*> &nodeList, int sta, int end) {
        if (sta > end || sta < 0 || end >= nodeList.size()) {
            return nullptr;
        }

        if (sta == end) {
            return new TreeNode(nodeList[sta]->val);
        }

        int mid = (sta + end) / 2;
        auto midNode = nodeList[mid];

        auto res = new TreeNode(midNode->val);

        res->left = buildTreeHelper(nodeList, sta, mid - 1);
        res->right = buildTreeHelper(nodeList, mid + 1, end);
        return res;
    }
};
// @lc code=end

