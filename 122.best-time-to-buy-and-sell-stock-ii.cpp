#include <vector>
#include <algorithm> // 用于max函数

using namespace std;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; // 初始化最大利润为0
        // 遍历价格数组，从第2天开始（索引1）
        for (int i = 1; i < prices.size(); ++i) {
            // 如果当天价格比前一天高，就把差价加入利润
            max_profit += max(0, prices[i] - prices[i-1]);
        }
        return max_profit; 
    }
};
// @lc code=end

