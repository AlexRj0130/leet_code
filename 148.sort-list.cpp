/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        // 边界条件：空链表或只有一个节点，直接返回
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1. 先统计链表长度，用于后续分块迭代
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        // 2. 虚拟头节点（简化链表合并时的边界处理）
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 3. 迭代归并：子链表长度从 1 开始，每次翻倍（1→2→4→...）
        for (int subLen = 1; subLen < len; subLen *= 2) {
            ListNode* prev = dummy;  // 合并后链表的前驱节点
            ListNode* curr = dummy->next;  // 当前待分割的节点

            while (curr != nullptr) {
                // 第一步：找到第一个子链表（长度 subLen）
                ListNode* left = curr;
                for (int i = 1; i < subLen && curr->next != nullptr; i++) {
                    curr = curr->next;
                }

                // 第二步：找到第二个子链表（长度 subLen）
                ListNode* right = curr->next;
                curr->next = nullptr;  // 切断第一个子链表和后续的连接
                curr = right;
                for (int i = 1; i < subLen && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }

                // 第三步：切断第二个子链表和后续的连接（记录后续节点）
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }

                // 第四步：合并两个有序子链表，并连接到 prev 之后
                prev->next = merge(left, right);

                // 第五步：移动 prev 到合并后的链表末尾，准备下一次合并
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;  // 处理下一组子链表
            }
        }

        ListNode* sortedHead = dummy->next;
        delete dummy;  // 释放虚拟节点内存
        return sortedHead;
    }
private:
    // 辅助函数：合并两个有序链表（经典题，LeetCode 21 题）
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // 拼接剩余节点
        curr->next = (l1 != nullptr) ? l1 : l2;

        ListNode* mergedHead = dummy->next;
        delete dummy;  // 释放虚拟节点内存
        return mergedHead;
    }
};
// @lc code=end

int main() {
    ListNode *head = new ListNode(4, 
        new ListNode(2, 
            new ListNode(1, 
                new ListNode(3))));

    Solution sol;
    sol.sortList(head);

    return 0;
}
