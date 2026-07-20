#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // dp[i][k] = min(for each j 从 k - 1 开始，一直到 i - 1, max(dp[j][k - 1], sumRange(j + 1, i)))
        int size = nums.size();

        vector<vector<long long>> dp = vector<vector<long long>>(size + 1, vector<long long>(k + 1, LLONG_MAX));
        vector<long long> pre(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                for (int x = 0; x < i; ++x) {
                    if (dp[x][j - 1] >= LLONG_MAX) {
                        continue;
                    }
                    long long tmp = max(dp[x][j - 1], pre[i] - pre[x]);
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }

        return dp[size][k];
    }
};
// @lc code=end

