/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        } 

        int sizeA = getListSize(headA);
        int sizeB = getListSize(headB);
        
        auto pReadA = headA;
        auto pReadB = headB;
        if (sizeA > sizeB) {
            pReadA = forwardSteps(pReadA, sizeA - sizeB);
        } else {
            pReadB = forwardSteps(pReadB, sizeB - sizeA);
        }

        while (pReadA != nullptr && pReadB != nullptr) {
            if (pReadA == pReadB) {
                return pReadA;
            }
            pReadA = pReadA->next;
            pReadB = pReadB->next;
        }

        return nullptr;
    }

private:
    int getListSize(ListNode *head) {
        int size = 0;
        while (head != nullptr) {
            ++size;
            head = head->next;
        }

        return size;
    }

    ListNode *forwardSteps(ListNode *head, int steps) {
        while (steps > 0) {
            if (head == nullptr) {
                return head;
            }
            head = head->next;
            --steps;
        }
        return head;
    }
};
// @lc code=end

