#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() <= 0) {
            return 0;
        } 

        if (stones.size() == 1) {
            return stones[0];
        }

        priority_queue<int, vector<int>, std::less<int>> pQueue;
        for (int i = 0; i < stones.size(); ++i) {
            pQueue.push(stones[i]);
        }

        while (!pQueue.empty()) {
            if (pQueue.size() == 1) {
                return pQueue.top();
            }

            auto val1 = pQueue.top();
            pQueue.pop();
            auto val2 = pQueue.top();
            pQueue.pop();

            auto remain = val1 - val2;
            if (remain > 0) {
                pQueue.push(remain);
            }
        }

        return 0;
    }
};
// @lc code=end

int main() {
    vector<int> nums{2,7,4,1,8,1};
    Solution sol;
    sol.lastStoneWeight(nums);
    return 0;
}
