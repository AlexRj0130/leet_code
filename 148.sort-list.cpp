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
        int listLen = getListLen(head);  
        if (listLen <= 1) {
            return head;
        }

        ListNode *resHead = nullptr, *resRear = nullptr;
        quickSort(head, listLen, resHead, resRear);

        return resHead;
    }
private:
    void quickSort(ListNode* head, int len, ListNode * &resHead, ListNode * &resRear) {
        if (head == nullptr || len <= 1) {
            resHead = resRear = head;
            return;
        }

        int midVal = getMidVal(head, len);

        ListNode midHeadTmp = ListNode(), *midRear = &midHeadTmp;
        ListNode leftHeadTmp = ListNode(), *leftRear = &leftHeadTmp;
        ListNode rightHeadTmp = ListNode(), *rightRear = &rightHeadTmp;
        int midLen = 0, leftLen = 0, rightLen = 0;

        ListNode * pRead = head;
        for (int i = 0; i < len && pRead != nullptr; ++i) {
            if (pRead->val == midVal) {
                midRear->next = pRead;
                midRear = pRead;
                ++midLen;
            } else if (pRead->val < midVal) {
                leftRear->next = pRead;
                leftRear = pRead;
                ++leftLen;
            } else {
                rightRear->next = pRead;
                rightRear = pRead;
                ++rightLen;
            }
            pRead = pRead->next;
            midRear->next = nullptr;
            leftRear->next = nullptr;
            rightRear->next = nullptr;
        }

        resHead = midHeadTmp.next;
        resRear = midRear;
        if (midLen == len) {
            return;
        }

        quickSort(leftHeadTmp.next, leftLen, leftHeadTmp.next, leftRear);
        quickSort(rightHeadTmp.next, rightLen, rightHeadTmp.next, rightRear);

        if (leftLen > 0) {
            resHead = leftHeadTmp.next;
            leftRear->next = midHeadTmp.next;
        }

        if (rightLen > 0) {
            resRear->next = rightHeadTmp.next;
            resRear = rightRear;
        }
    }

    int getListLen(ListNode* head) {
        int res = 0;
        while (head != nullptr) {
            ++res;
            head = head->next;
        }
        return res;
    }

    int getMidVal(ListNode* head, int len) {
        int midLen = len / 2;
        int midVal = 0;
        for (int i = 0; i < midLen && head != nullptr; ++i) {
            midVal = head->val;
            head = head->next;
        }

        return midVal;
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
