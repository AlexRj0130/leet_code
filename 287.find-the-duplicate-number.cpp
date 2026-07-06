#include<vector>
#include<iostream>

using namespace std;

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }

        int index = 0;
        while (index = findNextStartIndex(nums, index), index >= 0) {
            int tmpVal = nums[index];
            nums[index] = -1;
            while (tmpVal != -1) {
                if (nums[tmpVal - 1] == -1) {
                    nums[tmpVal - 1] = tmpVal;
                    tmpVal = -1;
                    break;
                } else if (nums[tmpVal - 1] == tmpVal) {
                    return tmpVal;
                }
                
                int tmp = nums[tmpVal - 1];
                nums[tmpVal - 1] = tmpVal;
                tmpVal = tmp;
            } 
        } 
        
        return -1;
    }
private:
    int findNextStartIndex(const vector<int>& nums, int sta) {
        while (sta < nums.size()) {
            if (nums[sta] == -1) {
                ++sta;
                continue;
            } else if (nums[sta] == sta + 1) {
                ++sta;
                continue;
            } else {
                return sta;
            }
        }
        return -1;
    }

};
// @lc code=end

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution sol;

    int res = sol.findDuplicate(nums);
    std::cout << res << std::endl;
}