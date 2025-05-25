#include <limits>
#include <iostream>

/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == std::numeric_limits<int>::min() && divisor == (-1)) {
            return std::numeric_limits<int>::max();
        }        
        if (divisor == 0) {
            return dividend >= 0 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
        }
        if (divisor == 1 || dividend == 0) {
            return dividend;
        }

        int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
        int res = 0;
        
        long long tmpDividend = dividend > 0 ? dividend : (0 - (long long)dividend);
        long long tmpDivisor = divisor > 0 ? divisor : (0 - (long long)divisor);
        while (tmpDividend >= tmpDivisor) {
            long long scaled = 1;
            long long scaledDivisor = tmpDivisor;
            long long scaledDivisorTmp = scaledDivisor;
            while (scaledDivisorTmp = scaledDivisorTmp << 1, scaledDivisorTmp < tmpDividend) {
                scaled = scaled << 1;
                scaledDivisor = scaledDivisorTmp;
            }

            res += scaled;
            tmpDividend = tmpDividend - scaledDivisor;
        }

        return sign >= 0 ? int(res) : int(0 - res);
    }
};
// @lc code=end

int main() {
    Solution sol;
    auto res = sol.divide(2147483647, 2);
    std::cout << "res = " << res << std::endl;

    return 0;
}

