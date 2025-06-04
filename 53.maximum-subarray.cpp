#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        } 

        int maxSum = nums[0];
        int preSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            preSum = nums[i] + preSum > nums[i] ? nums[i] + preSum : nums[i];
            maxSum = maxSum > preSum ? maxSum : preSum;
        }
        return maxSum;
    }
};
// @lc code=end

