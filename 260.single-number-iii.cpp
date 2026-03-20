#include <unordered_set>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> resSet; 

        for (auto num : nums) {
            if (resSet.contains(num)) {
                resSet.erase(num);
            } else {
                resSet.insert(num);
            }
        }

        return vector<int>(resSet.begin(), resSet.end());
    }
};
// @lc code=end

