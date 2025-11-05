/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || head == nullptr) {
            return head;
        } 

        ListNode *pFirst = head, *pSecond = head, *pSecondPre = nullptr;
        while (n > 0 && pFirst != nullptr) {
            pFirst = pFirst->next;
            --n;
        }

        while (pFirst != nullptr) {
            pFirst = pFirst->next;
            pSecondPre = pSecond;
            pSecond = pSecond->next;
        }

        if (pSecondPre == nullptr) {
            head = pSecond->next;
        } else {
            pSecondPre->next = pSecond->next;
        }
        pSecond->next = nullptr;
        return head;
    }
};
// @lc code=end

