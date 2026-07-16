/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode * pFast = head->next->next, * pSlow = head->next;
        while (pFast != nullptr && pFast->next != nullptr && pFast != pSlow) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
       
        if (pFast != pSlow) {
            return nullptr;
        }

        pSlow = head;
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        return pSlow;
    }
};
// @lc code=end

