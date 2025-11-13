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
        vector<int> res(nums.size(), 0);
        int count = 0;
        for (auto item : nums) {
            if (item == 0) {
                continue;
            }
            res[count++] = item;
        }
        nums.swap(res);
    }
private:
};
// @lc code=end

