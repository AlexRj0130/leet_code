/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) {
            return list1 != nullptr ? list1 : list2;
        } 

        ListNode *res = nullptr, *pRear = nullptr, *p1 = list1, *p2 = list2;
        while(p1 != nullptr && p2 != nullptr) {
            ListNode *pNext = nullptr;
            if (p1->val <= p2->val) {
                pNext = p1;
                p1 = p1->next;
            } else {
                pNext = p2;
                p2 = p2->next;
            }
            pNext->next = nullptr;

            if (pRear == nullptr) {
                res = pRear = pNext;
            } else {
                pRear->next = pNext;
                pRear = pNext;
            }
        }

        if (p1 != nullptr) {
            pRear->next = p1;
        }

        if (p2 != nullptr) {
            pRear->next = p2;
        }

        return res;
    }
};
// @lc code=end

