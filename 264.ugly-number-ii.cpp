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
        if (n <= 1) {
            return 1;
        } 

        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int p2Tmp = dp[p2] * 2;
            int p3Tmp = dp[p3] * 3;
            int p5Tmp = dp[p5] * 5;
            dp[i] = min({p2Tmp, p3Tmp, p5Tmp});

            if (dp[i] == p2Tmp) ++p2;
            if (dp[i] == p3Tmp) ++p3;
            if (dp[i] == p5Tmp) ++p5;
        }

        return dp[n - 1];
    }
};
// @lc code=end

