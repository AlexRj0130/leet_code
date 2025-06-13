#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        } 

        if (nums.size() == 2) {
            return nums[0] == nums[1];
        }

        sort(nums.begin(), nums.end());
        int sumTotal = accumulate(nums.begin(), nums.end(), 0);
        
        if (sumTotal % 2 != 0) {
            return false;
        }
        
        int target = sumTotal / 2;
        if (nums[nums.size() - 1] > target) {
            return false;
        }

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (const auto & num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }

            if (dp[target]) {
                return true;
            }
        }

        return dp[target];
    }
};
// @lc code=end

int main() {
    auto data = vector<int>({1, 3, 4, 6, 7, 9});
    Solution sol;
    sol.canPartition(data);
    return 0;
}