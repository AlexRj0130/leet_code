#include <vector>
#include <map>

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
        int res = 0;
        unordered_map<int, bool> numsMap;
        for (int i = 0; i < nums.size(); ++i) {
            numsMap.insert({nums[i], true});
        }

        for (int i = 0; i < nums.size(); ++i) {
            int numLeft = nums[i] - 1;
            int numRight = nums[i] + 1;
            int resTmp = 1;

            while(numsMap.contains(numLeft)) {
                numsMap.erase(numLeft);
                ++resTmp;
                --numLeft;
            }

            while (numsMap.contains(numRight)) {
                numsMap.erase(numRight);
                ++resTmp;
                ++numRight;
            }

            res = max(res, resTmp);
        }

        return res;
    }
};
// @lc code=end

