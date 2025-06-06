#include <vector>

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        int resF = -1;
        for (int k = 2; k <= n; ++k) {
            int res = 1;
            int count = k;
            int val = n / k;
            int remain = n % k;
            while (count > 0) {
                if (remain > 0) {
                    res *= (val + 1);
                    --remain;
                } else {
                    res *= val;
                }
                --count;
            }
            resF = std::max(resF, res);
        } 

        return resF;
    }
};
// @lc code=end

