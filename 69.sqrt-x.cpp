#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long res = 0;
        long long left = 0, right = x;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid <= x ) {
                res = max(res, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
// @lc code=end

