#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class PriorityQueueWithSize {
public:
    PriorityQueueWithSize(int size) : size(size), pQueue(compare) {}

    void push(pair<int, int> item) {
        if (pQueue.size() < size) {
            pQueue.push(item);
            return;
        }

        auto topItem = pQueue.top();
        if (!compare(topItem, item)) {
            return;
        }

        pQueue.pop();
        pQueue.push(item);
    };

    pair<int, int> topAndPop() {
        auto res = pQueue.top();
        pQueue.pop();
        return res;
    }

public:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>,  decltype(compare)> pQueue;
    int size;
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2fre; 
        for (int i = 0; i < nums.size(); ++i) {
            if (num2fre.contains(nums[i])) {
                num2fre[nums[i]] += 1;
            } else {
                num2fre[nums[i]] = 1;
            }
        }

        PriorityQueueWithSize pQueue(k);

        for (auto item : num2fre) {
            pQueue.push(item);
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pQueue.topAndPop().first);
        }

        return res;
    }
};
// @lc code=end

