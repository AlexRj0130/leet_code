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

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            res = max(dp[i], res);
        }

        return res;
    }
};
// @lc code=end

