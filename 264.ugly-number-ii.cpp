#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 3) {
            return n;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int tmp2 = dp[p2] * 2;
            int tmp3 = dp[p3] * 3;
            int tmp5 = dp[p5] * 5;

            dp[i] = min({tmp2, tmp3, tmp5});
            if (dp[i] == tmp2) ++p2;
            if (dp[i] == tmp3) ++p3;
            if (dp[i] == tmp5) ++p5;
        }

        return dp[n - 1];
    }
};
// @lc code=end

