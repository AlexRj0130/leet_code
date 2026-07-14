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
        // 思路：
        //  先找到第一个 0 的位置 zeroIndex
        //  然后，从第一个 0 的位置 zeroIndex 开始，向后找到第一个非 0 的位置 notZeroIndex
        //  交换 zeroIndex 和 notZeroIndex 对应的数值
        //  然后从 zeroIndex 开始（不含）找到下一个 0 的位置 zeroIndex
        //  重复上述过程

        int zeroIndex = findNextZeroIndex(nums, 0);
        if (zeroIndex < 0) {
            return;
        }

        int notZeroIndex = -1;
        while (notZeroIndex = findNextNotZeroIndex(nums, zeroIndex), notZeroIndex > 0) {
            swap(nums[zeroIndex], nums[notZeroIndex]);
            zeroIndex = findNextZeroIndex(nums, zeroIndex + 1);
        }
    }
private:
    int findNextZeroIndex(const vector<int>& nums, int sta) {
        if (sta < 0 || sta >= nums.size()) {
            return -1;
        }

        for (int i = sta; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return i;
            }
        }

        return -1;
    }

    int findNextNotZeroIndex(const vector<int>& nums, int sta) {
        if (sta < 0 || sta >= nums.size()) {
            return -1;
        }

        for (int i = sta; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                return i;
            }
        }

        return -1;
    } 
};
// @lc code=end

