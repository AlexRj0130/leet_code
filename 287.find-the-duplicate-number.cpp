#include<vector>
#include<iostream>

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
        for (int i = 0; i < nums.size(); ++i) {
            int index = findNextWrongIndex(nums, i);
            int num = nums[index];
            nums[index] = 0;
            int numTargetIndex = num2Index(num);
            while (nums[numTargetIndex] != 0) {
                if (nums[numTargetIndex] == num) {
                    return num;
                }

                int tmp = nums[numTargetIndex];
                nums[numTargetIndex] = num;
                num = tmp;
                numTargetIndex = num2Index(num);
            }
            nums[numTargetIndex] = num;
        }
        return 0;
    }
private:
    int findNextWrongIndex(const vector<int>& nums, int sta) {
        for (int i = sta; i < nums.size(); ++i) {
            if (nums[i] != index2Num(i)) {
                return i;
            }
        }
        return -1;
    }

    int index2Num(int index) {
        return index + 1;
    }

    int num2Index(int num) {
        return num - 1;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution sol;

    int res = sol.findDuplicate(nums);
    std::cout << res << std::endl;
}