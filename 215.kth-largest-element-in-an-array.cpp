#include <queue>
#include <vector>

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
        if (nums.size() < k) {
            return 0;
        } 

        priority_queue<int> pQueue;
        for (int i = 0; i < nums.size(); ++i) {
            pQueue.push(nums[i]);
        }

        while(--k > 0) {
            pQueue.pop();
        }
        return pQueue.top();
    }
};
// @lc code=end

