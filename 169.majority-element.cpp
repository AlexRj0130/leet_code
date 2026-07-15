#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for (auto item : nums) {
            if (count == 0) {
                res = item, ++count;
            } else if (res == item) {
                ++count;
            } else {
                --count;
            }
        }
        return res;
    }
};
// @lc code=end

