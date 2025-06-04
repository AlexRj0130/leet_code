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
        int count = 0; 
        int res = 0;
        for (auto & item : nums) {
            if (count == 0) {
                res = item;
                ++count;
                continue;
            }

            count += (res == item ? 1 : -1);
        }
        
        return res;
    }
};
// @lc code=end

