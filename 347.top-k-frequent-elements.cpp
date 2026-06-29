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
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() <= 0) {
            return {};
        }

        map<int, int> num2count;
        for (auto item : nums) {
            ++num2count[item];
        }

        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        for (const auto & item : num2count) {
            if (que.size() < k) {
                que.push(item);
            } else if (que.top().second < item.second) {
                que.pop();
                que.push(item);
            }
        }

        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top().first);
            que.pop();
        }

        return res;
    }
};
// @lc code=end

