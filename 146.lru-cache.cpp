#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
struct AListNode {
    AListNode(int key, int val) : AListNode(key, val, nullptr, nullptr) {}
    AListNode(int key, int val, AListNode *pre, AListNode *next) : key(key), val(val), pre(pre), next(next) {}
    int key;
    int val;
    AListNode *pre; 
    AListNode *next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        if (capacity <= 0) {
            return;
        }
        mMaxCap = capacity; 
    }
    
    int get(int key) {
        if (!mKey2Map.contains(key)) {
            return -1;
        }

        auto node = mKey2Map[key];
        auto val = node->val;
        if (!isHeadNode(node)) {
            removeNode(node);
            insertNodeHead(node);
        }
        return val;
    }
    
    void put(int key, int value) {
        if (mKey2Map.contains(key)) {
            auto node = mKey2Map[key];
            node -> val = value;
            if (!isHeadNode(node)) {
                removeNode(node);
                insertNodeHead(node); 
            }
            return;
        }

        if (mCurSize < mMaxCap) {
            insertNodeHead(key, value);
            return;
        }

        auto node = removeNode(mListRear);
        node->key = key;
        node->val = value;
        insertNodeHead(node);
    }

private:
    bool isHeadNode(AListNode *node) {
        return node == mListHead;
    }

    AListNode * removeNode(int key) {
        if (!mKey2Map.contains(key)) {
            return nullptr;
        }
        return removeNode(mKey2Map[key]);
    }

    AListNode * removeNode(AListNode *node) { // 移除指定节点
        if (node == nullptr) {
            return nullptr;
        }

        if (mKey2Map.contains(node->key)) {
            mKey2Map.erase(node->key);
        }

        if (node == mListHead) {
            if (node == mListRear) {
                mListHead = nullptr;
                mListRear = nullptr;
                mCurSize = 0;

                node->pre = nullptr;
                node->next = nullptr;
                return node;
            }

            mListHead = mListHead->next;
            mListHead->pre = nullptr;
            --mCurSize;

            node->pre = nullptr;
            node->next = nullptr;
            return node;
        }

        if (node == mListRear) {
            mListRear = mListRear->pre;
            mListRear->next = nullptr;
            --mCurSize;

            node->pre = nullptr;
            node->next = nullptr;
            return node;
        }

        node->pre->next = node->next;
        node->next->pre = node->pre;
        --mCurSize;

        node->pre = nullptr;
        node->next = nullptr;
        return node;
    }

    void insertNodeHead(int key, int val) {
        insertNodeHead(new AListNode(key, val));
    }

    void insertNodeHead(AListNode *node) { // 将节点插入头部
        if (node == nullptr) {
            return;
        }

        mKey2Map[node->key] = node;

        if (mListHead == nullptr) {
            node->pre = nullptr;
            node->next = nullptr;
            mListHead = mListRear = node;
            ++mCurSize;
            return;
        }

        node->next = mListHead;
        node->pre = nullptr;
        mListHead->pre = node;
        mListHead = node;
        ++mCurSize;
        return;
    }

private:
    AListNode *mListHead{nullptr};
    AListNode *mListRear{nullptr};
    unordered_map<int, AListNode*> mKey2Map; 
    int mCurSize{0};
    int mMaxCap{1};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 2);
    cache.put(2, 3);
    cache.put(4, 1);
    cout << "get = " << cache.get(1) << endl; // = 1
    cout << "get = " << cache.get(2) << endl; // = -1
    return 0;
}
