#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        initDp(nums);

        for (int i = 2; i <= mNumsSize; ++i) {
            int sumTmp = nums[i-1];
            if (mDpFlagVec[i - 1]) {
                sumTmp += mDpSumVec[i - 2];
            } else {
                sumTmp += mDpSumVec[i - 1];
            }

            if (sumTmp > mDpSumVec[i - 1]) {
                mDpSumVec[i] = sumTmp;
                mDpFlagVec[i] = true;
            } else {
                mDpSumVec[i] = mDpSumVec[i - 1];
            }
        }

        return mDpSumVec[mNumsSize];
    }
private:
    void initDp(const vector<int>& nums) {
        mNumsSize = nums.size();
        mDpFlagVec = vector<bool>(mNumsSize + 1, false);
        mDpSumVec = vector<int>(mNumsSize + 1, false);

        mDpFlagVec[0] = false;
        mDpFlagVec[1] = true;

        mDpSumVec[0] = 0;
        mDpSumVec[1] = nums[0];
    }

private:
    vector<bool> mDpFlagVec;
    vector<int> mDpSumVec;
    int mNumsSize{0};
};
// @lc code=end

