#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        } else if (nums.size() <= 1) {
            return 1;
        }

        vector<int> numStack, signStack;
        numStack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int topNum = numStack[numStack.size() - 1];
            int minus = nums[i] - topNum;
            if (minus == 0) {
                continue;
            } else {
                if (signStack.size() == 0) {
                    signStack.push_back(minus);
                    numStack.push_back(nums[i]);
                } else {
                    int topSign = signStack[signStack.size() - 1];
                    if (topSign * minus < 0) {
                        signStack.push_back(minus);
                        numStack.push_back(nums[i]); 
                    } else {
                        numStack[numStack.size() - 1] = nums[i];
                    }
                }
            } 
        }

        return numStack.size();
    }
};
// @lc code=end

