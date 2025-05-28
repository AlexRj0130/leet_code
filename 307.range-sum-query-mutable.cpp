#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) : mDataSize(nums.size()), mSeg(4 * nums.size(), 0) {
        if (nums.size() <= 0) {
            return;
        }

        buildSeg(nums, 0, nums.size() - 1, 0);
    }
    
    void update(int index, int val) {
        if (mDataSize <= 0 || index < 0 || index >= mDataSize) {
            return;
        }

        updateSeg(0, mDataSize - 1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        if (mDataSize <= 0) {
            return 0;
        }
        return sumSeg(left, right, 0, mDataSize - 1, 0);
    }

private:
    void buildSeg(const vector<int>& nums, int left, int right, int pos) {
        if (left >= right) {
            mSeg[pos] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        buildSeg(nums, left, mid, pos * 2 + 1);
        buildSeg(nums, mid + 1, right, pos * 2 + 2);
        mSeg[pos] = mSeg[pos * 2 + 1] + mSeg[pos * 2 + 2];
        return;
    }

    void updateSeg(int left, int right, int pos, int index, int val) {
        if (index < left || index > right) {
            return;
        }

        if (left == right) {
            if (index == left) {
                mSeg[pos] = val;
            }
            return;
        }

        int mid = (left + right) / 2;
        updateSeg(left, mid, pos * 2 + 1, index, val);
        updateSeg(mid + 1, right, pos * 2 + 2, index, val);
        mSeg[pos] = mSeg[pos * 2 + 1] + mSeg[pos * 2 + 2];
    }

    int sumSeg(int queryLeft, int queryRight, int left, int right, int pos) {
        if (queryLeft <= left && queryRight >= right) {
            return mSeg[pos];
        }

        if (queryLeft > right || queryRight < left) {
            return 0;
        }

        int mid = (left + right) / 2;
        return sumSeg(queryLeft, queryRight, left, mid, pos * 2 + 1) + 
            sumSeg(queryLeft, queryRight, mid + 1, right, pos * 2 + 2);
    }

private:
    int mDataSize;
    vector<int> mSeg;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    auto vec = vector<int>{9, -8};
    NumArray sol(vec);
    sol.update(0, 3);
    cout << "sumRange = " << sol.sumRange(1, 1) << endl;
    cout << "sumRange = " << sol.sumRange(0, 1) << endl;
    sol.update(1, -3);
    cout << "sumRange = " << sol.sumRange(0, 1) << endl;
    return 0;
}

