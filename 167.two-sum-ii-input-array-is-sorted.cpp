#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res; 
        int left = 1, right = numbers.size();
        
        while (left < right) {
            int tmp = numbers[left-1] + numbers[right-1];
            if (tmp < target) {
                ++left;
            } else if (tmp > target) {
                --right;
            } else {
                res.push_back(left);
                res.push_back(right);
                return res;
            }
        }

        return res;
    }
};
// @lc code=end

