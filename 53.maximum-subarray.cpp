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

        if (nums.size() <= 1) {
            return nums[0];
        }

        int res = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            maxSum = nums[i] > nums[i] + maxSum ? nums[i] : nums[i] + maxSum;
            res = res > maxSum ? res : maxSum;
        }

        return res;
    }
};
// @lc code=end

