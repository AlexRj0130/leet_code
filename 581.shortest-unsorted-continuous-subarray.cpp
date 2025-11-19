#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        } 

        int minRevNum = 0, minRevNumIndex = 0;
        int maxRevNum = 0, maxRevNumIndex = 0;
        bool findMinRevNum = false, findMaxRevNum = false;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (findMinRevNum == false) {
                    minRevNum = nums[i];
                    minRevNumIndex = i;
                    findMinRevNum = true;
                } else {
                    if (nums[i] < minRevNum) {
                        minRevNum = nums[i];
                        minRevNumIndex = i;
                    }
                }

                if (findMaxRevNum == false) {
                    maxRevNum = nums[i - 1];
                    maxRevNumIndex = i - 1;
                    findMaxRevNum = true;
                } else {
                    if (nums[i - 1] > maxRevNum) {
                        maxRevNum = nums[i - 1];
                        maxRevNumIndex = i - 1;
                    }
                }
            }
        }

        if (findMinRevNum == false || findMaxRevNum == false) {
            return 0;
        }
        
        int minTargetIndex = 0, maxTargetIndex = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= minRevNum) {
                minTargetIndex = i + 1;
                continue;
            }
            break;
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= maxRevNum) {
                maxTargetIndex = i - 1;
                continue;
            }
            break;
        }

        return maxTargetIndex - minTargetIndex + 1;
    }
};
// @lc code=end

