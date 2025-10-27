#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left >= right) {
            return head;
        } 

        ListNode *pPre = nullptr, *pNext = head;
        stack<ListNode*> nodeStack;
        for (int i = 1; i <= right && pNext != nullptr; ++i) {
            if (i < left) {
                pPre = pNext;
            } else if (i <= right) {
                nodeStack.push(pNext);
            }
            pNext = pNext->next;
        }

        if (nodeStack.size() < (right - left + 1)) {
            return head;
        }

        while (!nodeStack.empty()) {
            auto item = nodeStack.top();
            nodeStack.pop();

            item->next = pNext;

            if (pPre != nullptr)  {
                pPre->next = item;
                pPre = item;
            } else {
                head = pPre = item;
            }
        }

        return head;
    }
};
// @lc code=end

int main() {
    ListNode *head = new ListNode(1, 
        new ListNode(2, 
            new ListNode(3, 
                new ListNode(4, 
                    new ListNode(5)))));

    Solution sol;
    sol.reverseBetween(head, 2, 4);
    return 0;
}
