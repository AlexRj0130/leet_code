#include <map>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
struct CacheNode {
    int mKey;
    int mVal;
    CacheNode *mpPre, *mpNext; 
    CacheNode(int key, int val) {
        mKey = key;
        mVal = val;
        mpPre = nullptr;
        mpNext = nullptr;
    } 
    CacheNode(int key, int val, CacheNode * pPre, CacheNode * pNext) {
        mKey = key;
        mVal = val;
        mpPre = pPre;
        mpNext = pNext;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity; 
        mMap = map<int, CacheNode*>();
        mpHead = nullptr;
        mpRear = nullptr;
    }

    
    
    int get(int key) {
        if (mMap.contains(key)) {
            auto node = mMap.at(key);
            setNodeHead(node);
            return node->mVal;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (mMap.contains(key)) {
            auto node = mMap.at(key);
            node->mVal = value;
            setNodeHead(node);
            return;
        } 

        CacheNode * newNode = nullptr;
        if (mCapacity <= mMap.size()) {
            mMap.erase(mpRear->mKey);
            newNode = removeNode(mpRear);
            newNode->mKey = key;
            newNode->mVal = value;
        } else {
            newNode = new CacheNode(key, value);
        }

        setNodeHead(newNode);
        mMap[key] = newNode;
    }

    void getAndCout(int key) {
        cout << "key = " << key << ", val = " << get(key) << endl;
    }

private:
    void setNodeHead(CacheNode *node) {
        if (node == nullptr) {
            return;
        }

        if (node == mpHead) {
            return;
        }

        removeNode(node);

        if (mpHead == nullptr) {
            mpRear = mpHead = node;
            return;
        }

        node->mpNext = mpHead;
        mpHead->mpPre = node;
        mpHead = node;
    }

    CacheNode * removeNode(CacheNode *node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (mpHead == mpRear) {
            if (mpHead == nullptr) {
                return nullptr;
            }

            if (node==mpHead) {
                mpHead = mpRear = nullptr; 
                return node;
            }

            return node;
        }

        if (node == mpHead) {
            mpHead = mpHead->mpNext;
            mpHead->mpPre = nullptr;
        } else if (node == mpRear) {
            mpRear = mpRear->mpPre;
            mpRear->mpNext = nullptr;
        } else {
            if (node->mpPre != nullptr) {
                node->mpPre->mpNext = node->mpNext;
            }
            if (node->mpNext != nullptr) {
                node->mpNext->mpPre = node->mpPre;
            }
        }

        node->mpPre = node->mpNext = nullptr;
        return node;
    }

private:
    int mCapacity;
    map<int, CacheNode*> mMap;
    CacheNode *mpHead, *mpRear;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    auto cache = LRUCache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    cache.getAndCout(4);
    cache.getAndCout(3);
    cache.getAndCout(2);
    cache.getAndCout(1);
    cache.put(5, 5);
    cache.getAndCout(1);
    cache.getAndCout(2);
    return 0;
}
