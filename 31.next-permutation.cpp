#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        } 

        int i = nums.size() - 1; 
        while (i > 0 && nums[i] <= nums[i - 1]) {
            --i;
        }

        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i - 1]) {
            --j;
        }

        int tmp = nums[i - 1];
        nums[i - 1] = nums[j];
        nums[j] = tmp;
        sort(nums.begin() + i, nums.end());
    }
};
// @lc code=end

