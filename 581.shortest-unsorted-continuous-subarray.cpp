#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int minVal = nums[size - 1], maxVal = nums[0];
        int sta = -1, end = -2;

        for (int i = 1; i < size; ++i) {
            maxVal = max(maxVal, nums[i]);
            if (nums[i] < maxVal) {
                end = i;
            }
        }

        for (int i = size - 2; i >= 0; --i) {
            minVal = min(minVal, nums[i]);
            if (nums[i] > minVal) {
                sta = i;
            }
        }

        return end - sta + 1;
    }
};
// @lc code=end

