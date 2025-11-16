#include<vector>

using namespace std;

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 0) {
            return -1;
        } 

        int index = findNextIndex(nums, 0), count = nums.size();
        while (count > 0) {
            if (nums[index] != index + 1) {
                int targetIndex = nums[index] - 1;
                if (nums[targetIndex] == nums[index]) {
                    return nums[index];
                } else {
                    swap(nums[targetIndex], nums[index]);
                }
            } else {
                index = findNextIndex(nums, index);
            }
            --count;
        }

        return -1;
    }
private:
    int findNextIndex(const vector<int>& nums, int sta) {
        for (int i = sta; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

