#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pRes = nullptr, *pHeadRemain = head;
        ListNode *pPre = nullptr, *pRead = head; 
        stack<ListNode*> kStack;

        while (pRead != nullptr) {
            pHeadRemain = pRead;
            for (int i = 0; i < k && pRead != nullptr; ++i) {
                kStack.push(pRead); 
                pRead = pRead->next;
            }

            if (kStack.size() < k) {
                if (pPre != nullptr) {
                    pPre->next = pHeadRemain;
                }
                break; 
            }

            while (!kStack.empty()) {
                auto item = kStack.top();
                kStack.pop();

                if (pRes == nullptr) {
                    pRes = item;
                }

                if (pPre == nullptr) {
                    pPre = item;
                    pPre->next = nullptr;
                } else {
                    pPre->next = item;
                    pPre = item;
                    pPre->next = nullptr;
                }
            }
        }

        if (pRes == nullptr) {
            return head;
        } else {
            return pRes;
        }
    }
};
// @lc code=end

