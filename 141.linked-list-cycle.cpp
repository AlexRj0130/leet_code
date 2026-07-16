using namespace std;

/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode * pFast = head->next->next, *pSlow = head->next;
        while (pFast != nullptr && pFast->next != nullptr && pFast != pSlow) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }

        return pFast == pSlow;
    }
};
// @lc code=end

