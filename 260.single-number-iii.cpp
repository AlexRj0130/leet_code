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
        int xorTmp = 0; 
        for (auto num : nums) {
            xorTmp ^= num;
        }

        int mask = 1;
        while ((xorTmp & 1) == 0) {
            xorTmp = xorTmp >> 1;
            mask = mask << 1;
        }

        int a = 0, b = 0;
        for (auto num : nums) {
            if (num & mask) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,2,1,3,2,5};

    Solution sol;
    sol.singleNumber(nums);

    return 0;
}
