#include <map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num2index; 
        for (int i = 0; i < nums.size(); ++i) {
            num2index.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num1 = nums[i];
            int num2 = target - num1;
            if (num2index.contains(num2)) {
                int index2 = num2index[num2];
                if (i != index2) {
                    return {i, index2};
                }
            }
        }

        return {};
    }
};
// @lc code=end

int main() {
    vector<int> nums{3,2,4};

    Solution sol;
    sol.twoSum(nums, 6);

    return 0;
}

