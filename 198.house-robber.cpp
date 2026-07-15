#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        vector<int> dp1(nums.size(), 0); // 抢到第 i 家，但没有抢第 i 家的最大值
        vector<int> dp2(nums.size(), 0); // 抢到第 i 家，且有抢第 i 家的最大值

        dp2[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp1[i] = max(dp2[i - 1], dp1[i - 1]);
            dp2[i] = nums[i] + dp1[i - 1];
        }

        return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
    }
};
// @lc code=end

