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
        if (n == 0) return 1.0;
        if (n == 1) return x;

        bool sign = false;
        long long ln = n;
        if (n < 0) {
            sign = true;
            ln = 0 - ln;
        }

        double tmp = myPow(x, ln/2);
        tmp = ln % 2 ? tmp * tmp * x : tmp * tmp;
        tmp = sign ? 1/tmp : tmp;
        return tmp;
    }
};
// @lc code=end

