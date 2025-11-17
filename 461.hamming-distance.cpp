/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y; 
        int res = 0;
        while (tmp != 0) {
            if (tmp & 1) {
                ++res;
            }
            tmp = tmp >> 1;
        }
        return res;
    }
};
// @lc code=end

