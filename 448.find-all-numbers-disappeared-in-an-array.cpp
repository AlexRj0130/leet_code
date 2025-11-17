#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.size() <= 0) {
            return {};
        } 

        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            auto curNum = nums[i];
            if (curNum < 0) {
                ++i;
                continue;
            }
            
            auto targetIndex = num2Index(curNum);
            if (targetIndex == i) {
                ++i;
                continue;
            }

            auto targetNum = nums[targetIndex];
            if (curNum == targetNum) {
                nums[i] = -1;
                ++i;
                continue;
            }

            swap(nums[i], nums[targetIndex]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                res.push_back(index2Num(i));
            }
        }

        return res;
    }
private:
    int num2Index(int num) {
        return num - 1;
    }
    int index2Num(int index) {
        return index + 1;
    }
};
// @lc code=end

int main() {
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution sol;
    sol.findDisappearedNumbers(nums);
    return 0;
}

