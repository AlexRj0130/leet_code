#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        } 

        vector<int> record;
        record.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > record.back()) {
                record.push_back(nums[i]);
                continue;
            } else if (nums[i] == record.back()) {
                continue;
            } else {
                int index = findFirstGE(record, nums[i]);
                if (index != -1) {
                    record[index] = nums[i];
                }
            }
        }

        return record.size();
    }

private:
    int findFirstGE(const vector<int>&record, int target) {
        int start = 0, end = record.size() - 1;
        while(start <= end) {
            if (target <= record[start]) {
                return start;
            }

            if (target > record[end]) {
                return -1;
            }

            int mid = (start + end) / 2;
            if (target > record[mid]) {  // 说明 mid 左侧没有满足条件的结果，只能查找右侧
                start = mid + 1;
                continue;
            } else {
                end = mid - 1;
                if (target > record[end]) {
                    return mid;
                }
                continue;
            }
        }

        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution sol;

    sol.lengthOfLIS(nums);
    return 0;
}

