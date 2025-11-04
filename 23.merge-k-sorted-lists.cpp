#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        return divideMerge(lists, 0, lists.size() - 1);
    }
private:
    ListNode * divideMerge(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        if (start == end) {
            return lists[start];
        }

        if (end - start == 1) {
            return mergeTwoList(lists[start], lists[end]);
        }

        int mid = (start + end) / 2;
        auto subRes1 = divideMerge(lists, start, mid);
        auto subRes2 = divideMerge(lists, mid + 1, end);
        return mergeTwoList(subRes1, subRes2);
    } 

    ListNode* mergeTwoList(ListNode* root1, ListNode * root2) {
        if (root1 == nullptr) {
            return root2;
        }

        if (root2 == nullptr) {
            return root1;
        }

        ListNode *resHead = nullptr, *resRear = nullptr;
        while (root1 != nullptr && root2 != nullptr) {
            ListNode * tmp = root1->val <= root2->val ? root1 : root2;
            if (tmp == root1) {
                root1 = root1->next;
            }
            if (tmp == root2) {
                root2 = root2->next;
            }
            tmp->next = nullptr;

            if (resHead == nullptr) {
                resHead = resRear = tmp;
            } else {
                resRear->next = tmp;
                resRear = tmp;
            }
        }

        if (root1 != nullptr) {
            resRear->next = root1;
        }

        if (root2 != nullptr) {
            resRear->next = root2;
        }

        return resHead;
    }
};
// @lc code=end

