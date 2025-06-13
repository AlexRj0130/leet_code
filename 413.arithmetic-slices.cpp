#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        init(nums); 
        int count = 0;
        for (int i = 0; i <= int(nums.size()) - 3; ++i) {
            for (int j = i + 2; j < nums.size(); ++j) {
                int diffTmp = 0;
                if (isArithem(nums, i, j, diffTmp)) {
                    ++count;
                }
            }
        }
        return count;
    }
private:
    void init(const vector<int>& nums) {
        int numSize = nums.size();
        mDpVecDiff = vector<vector<int>>(numSize, vector<int>(numSize, 0));
        mDpVecInitFlag = vector<vector<bool>>(numSize, vector<bool>(numSize, false));
        mDpVecAriFlag = vector<vector<bool>>(numSize, vector<bool>(numSize, false));
    }

    bool isArithem(const vector<int>& nums, int start, int end, int &diff) {
        if (start < 0 || end > nums.size() - 1 || end - start < 2) {
            return false;
        }

        if (mDpVecInitFlag[start][end]) {
            diff = mDpVecDiff[start][end];
            return mDpVecAriFlag[start][end];
        }

        if (end - start == 2) {
            diff = nums[start + 1] - nums[start];
            int flagTmp = (nums[start + 1] - nums[start]) == (nums[start + 2] - nums[start + 1]);
            mDpVecInitFlag[start][end] = true;
            mDpVecAriFlag[start][end] = flagTmp;
            mDpVecDiff[start][end] = diff;
            return flagTmp;
        }

        mDpVecInitFlag[start][end] = true;
        mDpVecAriFlag[start][end] = isArithem(nums, start, end - 1, diff) && (nums[end] - nums[end - 1] == diff);
        mDpVecDiff[start][end] = diff;
        return mDpVecAriFlag[start][end];
    }

private:
    vector<vector<int>> mDpVecDiff;
    vector<vector<bool>> mDpVecAriFlag;
    vector<vector<bool>> mDpVecInitFlag;
};
// @lc code=end

int main() {
    auto data = vector<int>({1});
    Solution sol;
    cout << sol.numberOfArithmeticSlices(data) << endl;
    return 0;
}

