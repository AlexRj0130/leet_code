#include <algorithm>

using namespace std;

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
        int sizeA = getListSize(headA);
        int sizeB = getListSize(headB);
        
        auto head1 = sizeA >= sizeB ? headA : headB;
        auto head2 = sizeA < sizeB ? headA : headB;
        int sizeDiff = max(sizeA - sizeB, sizeB - sizeA);

        head1 = moveTargetStep(head1, sizeDiff);

        while (head1 != nullptr && head2 != nullptr) {
            if (head1 == head2) {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return nullptr;
    }

private:
    int getListSize(ListNode *head) {
        int res = 0;
        ListNode * read = head;
        while (read != nullptr) {
            ++res;
            read = read->next;
        }
        return res;
    }

    ListNode * moveTargetStep(ListNode * head, int target) {
        while (target > 0 && head != nullptr) {
            --target;
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

