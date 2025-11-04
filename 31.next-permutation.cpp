#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int revIndex = findFirstReverseIndex(nums);
        if (revIndex < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int fgtIndex = findFirstGTIndex(nums, nums[revIndex], revIndex + 1, nums.size() - 1);
        if (fgtIndex < 0) {
            return;
        }

        swap(nums[revIndex], nums[fgtIndex]);
        sort(nums.begin() + revIndex + 1, nums.end());
    }
private:
    int findFirstReverseIndex(const vector<int>& nums) {
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                continue;
            }
            return i;
        }

        return i;
    }

    int findFirstGTIndex(const vector<int>& nums, int target, int left, int right) {
        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
// @lc code=end


int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    sol.nextPermutation(nums);
    return 0;
}
