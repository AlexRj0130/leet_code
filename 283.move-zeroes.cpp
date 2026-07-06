#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroIndex = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                continue;
            }
            firstZeroIndex = i;
            break;
        }
        if (firstZeroIndex == -1) {
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (firstZeroIndex >= i) {
                continue;
            }
            nums[firstZeroIndex] = nums[i];
            nums[i] = 0;
            ++firstZeroIndex;
        }
    }
private:
};
// @lc code=end

