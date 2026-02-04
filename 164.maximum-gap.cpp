#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size(); 
        // 边界条件：元素个数小于2，返回0
        if (n < 2) {
            return 0;
        }

        // 1. 找数组的最小值和最大值
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        // 所有元素相同，间距为0
        if (maxNum == minNum) {
            return 0;
        }

        // 2. 计算桶的大小和数量
        int bucketSize = (maxNum - minNum) / n + 1;
        int bucketNum = (maxNum - minNum) / bucketSize + 1;

        // 每个桶存储 {桶内最小值, 桶内最大值}，初始化为 {INT_MAX, INT_MIN}
        const int minInt = numeric_limits<int>::min();
        const int maxInt = numeric_limits<int>::max();
        vector<pair<int, int>> bucket(bucketNum, {maxInt, minInt});

        // 3. 遍历数组，填充每个桶的最小/最大值
        for (auto num : nums) {
            int bucketIndex = (num - minNum) / bucketSize;
            bucket[bucketIndex].first = min(bucket[bucketIndex].first, num);
            bucket[bucketIndex].second = max(bucket[bucketIndex].second, num);
        }

        // 4. 遍历所有桶，计算最大间距
        int res = 0;
        int preMax = bucket[0].second; // 前一个非空桶的最大值，第 0 个桶一定存在。
        for (const auto &item : bucket) {
            // 跳过空桶
            if (item.second == minInt) {
                continue;
            }
            // 当前桶最小值 - 前一个桶最大值 = 候选间距
            res = max(res, item.first - preMax);
            preMax = item.second;
        }
        return res;
    }
};
// @lc code=end

