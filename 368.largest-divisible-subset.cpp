#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start

struct RecordNode {
    int val;
    int count;
    RecordNode *preNode;
    RecordNode(int val, int count, RecordNode *pre) : val(val), count(count), preNode(pre) {};  
    RecordNode(int val) : RecordNode(val, 1, nullptr) {};
    RecordNode(int val, RecordNode *pre) : val(val), preNode(pre) {
        if (preNode == nullptr) {
            count = 1;
            return;
        }
        count = preNode->count + 1;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        } else if (nums.size() == 1) {
            return nums;
        }

        std::sort(nums.begin(), nums.end());
        mRes = new RecordNode(nums[0]);
        mNodeVec.push_back(mRes);

        for (int i = 1; i < nums.size(); ++i) {
            RecordNode * targetNode = nullptr;
            int targetCount = -1;
            for (int j = mNodeVec.size() - 1; j >= 0; --j) {
                if (nums[i] % mNodeVec[j]->val != 0) {
                    continue;
                }
                if (mNodeVec[j]->count > targetCount) {
                    targetNode = mNodeVec[j];
                    targetCount = mNodeVec[j]->count;
                }
            }
            RecordNode * newNode = new RecordNode(nums[i], targetNode);
            if (newNode ->count > mMaxCount) {
                mMaxCount = newNode->count;
                mRes = newNode;
            }
            mNodeVec.push_back(newNode);
        }

        vector<int> res;
        while (mRes != nullptr) {
            res.push_back(mRes->val);
            mRes = mRes->preNode;
        }
        return res;
    }
private:
    RecordNode *mRes;
    vector<RecordNode *> mNodeVec;
    int mMaxCount{0};
};
// @lc code=end

int main() {
    vector<int> data({4,8,10,240});
    Solution sol;
    auto res = sol.largestDivisibleSubset(data);
    return 0;
}

