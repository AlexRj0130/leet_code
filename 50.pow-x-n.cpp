/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (n == 1) return x;

        bool sign = false;
        long long nTmp = n;
        if (nTmp < 0) {
            sign = true;
            nTmp = 0 - nTmp;
        }

        auto subTmp = myPow(x, nTmp / 2);
        auto res = nTmp % 2 ? subTmp * subTmp * x : subTmp * subTmp;
        return !sign ? res : 1 / res;
    }
};
// @lc code=end

