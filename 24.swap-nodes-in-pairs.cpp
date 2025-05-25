/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        } 

        ListNode *pre = head, *first = head, *second = first -> next;
        while (first != nullptr && second != nullptr) {
            first -> next = second -> next;
            second -> next = first;
            if (first == head) {
                head = second;
            } else {
                pre -> next = second;
            }

            pre = first;
            first = first -> next;
            if (first != nullptr) {
                second = first -> next;
            }
        }

        return head;
    }
};
// @lc code=end

