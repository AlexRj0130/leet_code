/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        } 

        ListNode *rear = nullptr, *pre = head, *read = head->next;
        head = nullptr;
        while (pre != nullptr && read != nullptr) {
            if (pre->val == read->val) {
                while (pre != nullptr && read != nullptr && pre->val == read->val) {
                    read = read->next;
                }
                pre = read;
                if (read != nullptr) {
                    read = read->next;
                }
            } else {
                if (head == nullptr) {
                    head = rear = pre;
                } else {
                    rear->next = pre;
                    rear = pre;
                }
                pre = read;
                read = read->next;
                rear->next = nullptr;
            }
        }
        
        if (pre != nullptr) {
            if (rear == nullptr) {
                head = rear = pre;
            } else {
                rear->next = pre;
                rear = rear->next;
            }
            rear->next = nullptr;
        }

        return head;
    }
};
// @lc code=end

