#include <vector>
#include <algorithm>

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
        if (nums.size() <= 1 || k <= 0) {
            return;
        }

        k = k % nums.size();

        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    } 
};
// @lc code=end

