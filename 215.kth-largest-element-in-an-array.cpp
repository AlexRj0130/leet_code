#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (const auto & val : nums) {
            pQueue.push(val);
        } 

        for (--k; k >= 0; --k) {
            if (k == 0) {
                return pQueue.top();
            }
            pQueue.pop();
        }

        return -1;
    }
private:
    std::priority_queue<int> pQueue;
};
// @lc code=end

