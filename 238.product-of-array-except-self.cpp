#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countZero = 0; 

        for (auto num : nums) {
            if (num == 0) {
                ++countZero;
            } else {
                product *= num;
            }
        }

        if (countZero >= 2) {
            return vector<int>(nums.size(), 0);
        }

        vector<int> res;
        for (auto num : nums) {
            if (countZero == 1) {
                if (num == 0) {
                    res.push_back(product);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(product/num);
            }
        }

        return res;
    }
};
// @lc code=end

