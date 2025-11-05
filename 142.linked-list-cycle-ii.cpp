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

        ListNode *pSlow = head, *pFast = head;
        do {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        } while (pSlow != nullptr
            && pFast != nullptr && pFast->next != nullptr && pSlow != pFast);

        if (pSlow != pFast) {
            return nullptr;
        }

        pSlow = head;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }
};
// @lc code=end

