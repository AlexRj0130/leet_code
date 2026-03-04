#include <numeric>

using namespace std;

/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};
// @lc code=end

int main() {
    Solution sol;
    sol.rangeBitwiseAnd(5, 7);
    return 0;
}