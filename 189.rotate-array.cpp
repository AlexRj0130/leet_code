#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k > 0) {
            rotateOneStep(nums);
            --k;
        } 
    }
private:
    void rotateOneStep(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int tmp = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i > 0; --i) {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
};
// @lc code=end

