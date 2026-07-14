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

        ListNode *leftLast = findSplitNode(head);
        ListNode *rightFirst = nullptr;
        if (leftLast == nullptr) {
            return false;
        }
        rightFirst = leftLast->next;
        leftLast->next = nullptr;
        rightFirst = reverseList(rightFirst);

        ListNode *left = head, *right = rightFirst;
        while (left != nullptr && right!= nullptr) {
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
private:
    ListNode * findSplitNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode * pSlow = head;
        ListNode * pFast = head;
        while (pFast->next != nullptr && pFast->next->next != nullptr) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        
        return pSlow;
    }

    ListNode * reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode * res = head; 
        head = head->next;
        res->next = nullptr;

        while (head != nullptr) {
            auto tmp = head->next;
            head->next = res;
            res = head;
            head = tmp;
        }

        return res;
    }
};
// @lc code=end

int main() {
    // ListNode * head = new ListNode(1, 
    //     new ListNode(2, 
    //         new ListNode(2, 
    //             new ListNode(1))));

    ListNode * head = new ListNode(1, 
        new ListNode(2));

    Solution sol;
    sol.isPalindrome(head);
    return 0;
}
