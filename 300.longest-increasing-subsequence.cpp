#include <vector>
#include <map>

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

        for (int i = 0; i < nums.size(); ++i) {
            auto nextGT = findNextGT(nums[i]);
            if (nextGT < 0) {
                record.push_back(nums[i]);
            } else {
                record[nextGT] = nums[i];
            }
        }

        return record.size();
    }
private:
    int findNextGT(int target) {
        if (record.size() == 0) {
            return -1;
        }

        if (record[0] >= target) {
            return 0;
        }

        if (record[record.size() - 1] < target) {
            return -1;
        }

        int left = 0, right = record.size() - 1, mid;
        while (left < right) {
            int mid = (left + right) / 2;
            if (record[mid] < target) {
                if (record[mid + 1] >= target) {
                    return mid + 1;
                }
                left = mid + 1;
            } else {
                if (record[mid - 1] < target) {
                    return mid;
                }
                right = mid - 1;
            }
        } 

        return mid;
    }

private:
    vector<int> record;
};
// @lc code=end

int main() {
    vector<int> data({1,3,6,7,9,4,10,5,6});
    Solution sol;
    sol.lengthOfLIS(data);
    return 0;
}
