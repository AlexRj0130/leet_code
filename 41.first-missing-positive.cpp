#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 1;
        } 

        // 第一次遍历，将所有负数全部调整为 0
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        // 第二次遍历，将数组中所有非0值的绝对值对应的下标中的数值调整为对应的负数
        for (int i = 0; i < nums.size(); ++i) {
            int index = -1;
            if (nums[i] > 0 && nums[i] <= nums.size()) {
                index = nums[i] - 1; 
            }
            if (nums[i] < 0 && nums[i] >= (0 - nums.size())) {
                index = (0 - nums[i]) - 1;
            }

            if (index < 0) {
                continue;
            }

            if (nums[index] < 0) {
                continue;
            } else if (nums[index] == 0) {
                nums[index] = 0 - index - 1;
            } else {
                nums[index] = 0 - nums[index];
            }
        }

        // 第三次遍历，找出首个不为负数的下标
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
// @lc code=end

