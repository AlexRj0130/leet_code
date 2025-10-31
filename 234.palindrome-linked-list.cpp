/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return false;
        } 

        if (head->next == nullptr) {
            return true;
        }

        auto pMid = findMid(head);
        auto pRearHead = pMid->next;
        pMid->next = nullptr;

        ListNode * pRead1 = head, *pRead2 = reverse(pRearHead);
        while (pRead1 != nullptr && pRead2 != nullptr) {
            if (pRead1->val != pRead2->val) {
                return false;
            }
            pRead1 = pRead1->next;
            pRead2 = pRead2->next;
        }

        return true;
    }
private:
    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *res = head;
        head = head->next;
        res->next = nullptr;
        while (head != nullptr) {
            auto tmp = head;
            head = head->next;
            tmp->next = res;
            res = tmp;
        }

        return res;
    }

    ListNode * findMid(ListNode *head) {
        ListNode *pSlow = head, *pFast = head;
        while (pSlow != nullptr && pFast != nullptr && 
            pFast->next != nullptr && pFast->next->next != nullptr) {
                pSlow = pSlow->next;
                pFast = pFast->next->next;
        }
        return pSlow;
    }

};
// @lc code=end

int main() {
    ListNode * head = new ListNode(1, 
        new ListNode(2, 
            new ListNode(2, 
                new ListNode(1))));
    Solution sol;
    sol.isPalindrome(head);
    return 0;
}
