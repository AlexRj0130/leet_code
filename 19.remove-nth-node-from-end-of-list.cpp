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
        if (head == nullptr || n <= 0) {
            return head;
        } else if (head -> next == nullptr && n == 1) {
            return nullptr;
        }

        ListNode *pPre = nullptr, *pTarget = head, *pCur = head;
        while (pCur != nullptr) {
            pCur = pCur -> next;
            if (n > 0 && (--n > 0)) {
            } else {
                pPre = pTarget;
                pTarget = pTarget -> next;
            }
        }

        return head;
    }
};
// @lc code=end


int main() {
    ListNode l5(5), l4(4, &l5), l3(3, &l4), l2(2, &l3), head(1, &l2);
    Solution sol;
    sol.removeNthFromEnd(&head, 5);
    return 0;
}

