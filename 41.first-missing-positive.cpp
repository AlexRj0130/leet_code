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

        int minValid = 1, maxValid = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            while (val >= minValid && val <= maxValid && nums[i] != i + 1) { // 先处理好当前 nums[i]，再进入下一个 i+1，避免遗漏。
                int tmp = nums[val - 1];
                nums[val - 1] = val;
                if (val != tmp) {  // 避免换回相同的值，进而进入死循环。
                    val = nums[i] = tmp;
                } else {
                    val = nums[i] = -1;
                }
            }   
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,1};
    
    Solution sol;
    auto res = sol.firstMissingPositive(nums);

    return 0;
}
