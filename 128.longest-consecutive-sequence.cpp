#include <vector>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 0) {
            return nums.size();
        }

        set<int> numSet; 
        int res = 1;
        for (auto num : nums) {
            numSet.insert(num);
        }

        for (auto num : nums) {
            int resTmp = 1;
            int numLeft = num;
            while (numSet.contains(--numLeft)) {
                numSet.erase(numLeft);
                ++resTmp;
            }

            int numRight = num;
            while (numSet.contains(++numRight)) {
                numSet.erase(numRight);
                ++resTmp;
            }

            res = max(res, resTmp);
        }

        return res;
    }
};
// @lc code=end

