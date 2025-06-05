#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int robFirst = tryRob(nums, true); 
        int robFirstNot = tryRob(nums, false);
        return robFirst > robFirstNot ? robFirst : robFirstNot;
    }

private:
    int tryRob(const vector<int>& nums, bool robFirst) {
        if (nums.size() <= 3) {
            auto res = max_element(nums.begin(), nums.end());
            return *res;
        }

        init(nums, robFirst);

        int start = 2;
        int end = nums.size();
        if (robFirst) {
            start = 3;
            end = nums.size() - 1;
        }

        for (int i = start; i <= end; ++i) {
            auto sumTmp = nums[i - 1];
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

        return mDpSumVec[end];
    }

    void init(const vector<int>& nums, bool rubFirst) {
        mNumsSize = nums.size();
        mDpFlagVec = vector<bool>(mNumsSize + 1, false);
        mDpSumVec = vector<int>(mNumsSize + 1, 0); 

        if (rubFirst) {
            mDpFlagVec[1] = true;
            mDpSumVec[1] = nums[0];
            mDpFlagVec[2] = true;
            mDpSumVec[2] = nums[0];
        } 
    }

private:
    vector<int> mDpSumVec;
    vector<bool> mDpFlagVec;
    int mNumsSize{0};
};
// @lc code=end

int main() {
    vector<int> data({4,1,2,7,5,3,1});
    Solution sol;
    auto res = sol.rob(data);
}