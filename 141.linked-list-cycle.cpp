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
        if (head==nullptr || head->next==nullptr) {
            return false;
        } 

        ListNode *pFast = head->next, *pSlow = head; 
        while (pFast != nullptr && pSlow != nullptr) {
            if (pFast == pSlow) {
                return true;
            }

            if (pFast->next == nullptr || pFast->next->next == nullptr) {
                return false;
            }
            pFast = pFast->next->next;

            if (pSlow->next == nullptr) {
                return false;
            }
            pSlow = pSlow->next;
        }

        return false;
    }
};
// @lc code=end

