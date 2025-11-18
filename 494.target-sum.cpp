#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        dfs(nums, 0, 0, target, res);
        return res;
    }
private:
    void dfs(const vector<int>& nums, int index, int curSum, const int target, int &res) {
        if (index >= nums.size()) {
            if (curSum == target) {
                ++res;
            }
            return;
        }

        dfs(nums, index + 1, curSum + nums[index], target, res);
        dfs(nums, index + 1, curSum - nums[index], target, res);
    }
};
// @lc code=end

