#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += ((nums[j] >> i) & 1);
            }
            
            sum %= 3;
            if (sum == 1) {
                res |= (1 << i);
            }
        }

        return res;
    }
};
// @lc code=end

