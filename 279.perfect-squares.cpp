#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        } 

        if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, n * 2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

